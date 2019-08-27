//_____________________________________________________________________________
//_____________________________________________________________________________
//                                CAMERA THREAD
// Acts like a camera allowing to acquire and manipulate frames.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "camerathread.h"

CameraThread::CameraThread()
{
    thread_active = true;
}

CameraThread::~CameraThread()
{
    thread_active = false;
    terminate();
    wait();
    if(Configurations::intrusion_detection_enabled)
    {
        cuda_detection_thread->~CudaDetectionThread();
    }
    close(mst_video_pipe);
    if(Configurations::source_choices[Configurations::source] == "Video file")
        close(mst_audio_pipe);
    std::system("bash -c \"killall ffmpeg\"");
    if(Configurations::source_choices[Configurations::source] == "Video file")
        audio_pipe_thread->~FeedAudioPipeThread();
    video_pipe_thread->~FeedVideoPipeThread();
    server_stream_thread->~ServerStreamThread();
    std::system("bash -c \"rm -R mst-temp\"");
}

/**
 * Defines the next video chunk, based on class variables.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::defineChunk()
{
    // Set begin and end H, M, S variables
    begin_h = static_cast<int>(begin_chunk / 3600);
    begin_chunk -= (begin_h * 3600);
    begin_m = static_cast<int>(begin_chunk / 60);
    begin_chunk -= (begin_m * 60);
    begin_s = static_cast<int>(begin_chunk);
    end_h = static_cast<int>(end_chunk / 3600);
    end_chunk -= (end_h * 3600);
    end_m = static_cast<int>(end_chunk / 60);
    end_chunk -= (end_m * 60);
    end_s = static_cast<int>(end_chunk);

    // Construct audiochunk and videochunk path based on tik tok strategy
    if(tik_tok)
    {
        Configurations::current_audio_path = "mst-temp/audio/tik";
        Configurations::current_frame_path = "mst-temp/frames/tik";
        tik_tok = false;
    }
    else
    {
        Configurations::current_audio_path = "mst-temp/audio/tok";
        Configurations::current_frame_path = "mst-temp/frames/tok";
        tik_tok = true;
    }
}

/**
 * Creates phisically on disk the next chunk of video and audio.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::createChunk()
{
    // Extract bmp frames and audio from video chunk
    // Extract frames
    timing = " -ss " + std::to_string(begin_h) + ":" +
            std::to_string(begin_m) + ":" + std::to_string(begin_s) +
            " -to " + std::to_string(end_h) + ":" + std::to_string(end_m) + ":"
            + std::to_string(end_s);
    command = "bash -c \"ffmpeg -i " + file_name + timing +
            " -compression_algo raw -pix_fmt rgb24 " +
            Configurations::current_frame_path + "/output%03d.bmp\"";
    std::system(command.c_str());
    // Extract audio
    command = "bash -c \"ffmpeg -i " + file_name + timing +
            " " + Configurations::current_audio_path + "/temp.aac -y\"";
    std::system(command.c_str());

    command = "bash -c \"ffmpeg -i " + Configurations::current_audio_path +
            "/temp.aac -ss 0 -to " +
            std::to_string(Configurations::video_chunk_seconds) +
            " " + Configurations::current_audio_path + "/audiochunk.aac -y\"";
    std::system(command.c_str());
}

/**
 * Manage a file manipulation and frames stream.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::captureFromFile()
{
    // Repair errors (if any) in input video file
    file_name = path + "/mst-temp/input_file.mkv";
    command = "ffmpeg -i " + Configurations::file_name +
            " -c copy -force_key_frames source " + file_name;
    std::system(command.c_str());

    // Activate feed ffmpeg audio and video pipe
    audio_pipe_thread = new FeedAudioPipeThread();
    QObject::connect(audio_pipe_thread, SIGNAL(notifyAudioToMstCondVar()),
                     this, SLOT(notifyAudioToMstCondVar()));
    audio_pipe_thread->start();

    video_pipe_thread = new FeedVideoPipeThread();
    QObject::connect(video_pipe_thread, SIGNAL(notifyVideoToMstCondVar()),
                     this, SLOT(notifyVideoToMstCondVar()));
    video_pipe_thread->start();

    // Get Video file length
    command = "ffprobe -v error -show_entries format=duration -of "
              "default=noprint_wrappers=1:nokey=1 " + file_name;
    strvideo_length = Configurations::execCmd(command.c_str());
    video_length = Configurations::strToPositiveDigit(strvideo_length);
    if(video_length == -1)
    {
        std::cout << "Invalid input file";
        return;
    }

    // Open mst pipes in write only mode.
    // Not really used to write inside the pipe
    if((mst_video_pipe = open(mstvideo_pipe_path.c_str(), O_WRONLY)) < 0)
    {
        std::cout << "Error opening MST video pipe\n";
    }
    if((mst_audio_pipe = open(mstaudio_pipe_path.c_str(), O_WRONLY)) < 0)
    {
        std::cout << "Error opening MST audio pipe\n";
    }

    // Extract the complete audio track
    command = "bash -c \"ffmpeg -i " + file_name +
            " -vn mst-temp/audio/complete.aac -y\"";
    std::system(command.c_str());

    begin_chunk = -1 * Configurations::video_chunk_seconds;
    end_chunk = 0;

    while(thread_active)
    {
        // Define the actual video chunk (in seconds) to use,
        // if EOF is reached, exit.
        begin_chunk += (end_chunk - begin_chunk);
        if(begin_chunk == video_length)
            break;
        if(end_chunk + Configurations::video_chunk_seconds < video_length)
            end_chunk += Configurations::video_chunk_seconds;
        else
            end_chunk += (video_length - end_chunk);

        defineChunk();
        createChunk();

        // Apply intrusion detection on chunk
        if(Configurations::intrusion_detection_enabled)
        {
            // Apply neural net on chunk frames
            emit runIntrusionDetection(false);
            sem_wait(&sem_detection_done);
        }

        // Apply eventually resize and blur filtering on chunk
        if(Configurations::frame_size_changed ||
                Configurations::blur_effect != 0)
        {
            QDir directory(QString::fromStdString
                           (Configurations::current_frame_path));
            QStringList images = directory.entryList
                    (QStringList() << "*.bmp", QDir::Files);
            foreach(QString filename, images) {
                emit imageScaleBlur(Configurations::current_frame_path
                              + "/" + filename.toStdString());
                sem_wait(&sem_picture);
            }
        }

        // Wait for signal to start feeding mst video
        sem_wait(&sem_video);
        command = "bash -c \"cat " + Configurations::current_frame_path +
                "/output*.bmp > " + mstvideo_pipe_path + " &\"";
        std::system(command.c_str());

        // Wait for signal to start feeding mst audio
        sem_wait(&sem_audio);
        // If the end of file is reached, wait for the end of stream
        if(end_chunk == video_length)
        {
            command = "bash -c \"cat " + Configurations::current_audio_path +
                    "/audiochunk.aac > " + mstaudio_pipe_path + " &\"";
            std::system(command.c_str());
        }
        else
        {
            command = "bash -c \"cat " + Configurations::current_audio_path +
                    "/audiochunk.aac > " + mstaudio_pipe_path + " &\"";
            std::system(command.c_str());
        }
    }
}

/**
 * Manage a camera frames manipulation and stream.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::captureFromCamera()
{
    cv::VideoCapture cap;
    cv::Mat frame;

    if(!cap.open(0))
        return;

    cap >> frame;

    Configurations::frame_width = frame.cols;
    Configurations::frame_height = frame.rows;

    video_pipe_thread = new FeedVideoPipeThread();
    QObject::connect(video_pipe_thread, SIGNAL(notifyVideoToMstCondVar()),
                     this, SLOT(notifyVideoToMstCondVar()));
    video_pipe_thread->start();

    // Open mst pipes in write only mode.
    // Not really used to write inside the pipe
    if((mst_video_pipe = open(mstvideo_pipe_path.c_str(), O_WRONLY)) < 0)
    {
        std::cout << "Error opening MST video pipe\n";
    }

    while(thread_active)
    {
        // Define videochunk_out_path
        if(tik_tok)
        {
            Configurations::current_frame_path = "mst-temp/frames/tik";
            tik_tok = false;
        }
        else
        {
            Configurations::current_frame_path = "mst-temp/frames/tok";
            tik_tok = true;
        }

        // Take a frame from camera
        cap >> frame;

        // Save image to /mst-temp/frames tik-tok folder
        emit saveCameraFrame(frame);
        sem_wait(&sem_camera_frame);

        // Apply intrusion detection
        if(Configurations::intrusion_detection_enabled)
        {
            // Apply neural net on frame
            emit runIntrusionDetection(true);
            sem_wait(&sem_detection_done);
        }

        // Apply eventually resize and blur filtering
        if(Configurations::frame_size_changed ||
                Configurations::blur_effect != 0)
        {
            emit imageScaleBlur(Configurations::current_frame_path +
                                "/output.bmp");
            sem_wait(&sem_picture);
        }

        // Wait for signal to start feeding mst video
        sem_wait(&sem_video);
        command = "bash -c \"cat " + Configurations::current_frame_path +
                "/output.bmp > " + mstvideo_pipe_path + "\"";
        std::system(command.c_str());

    }
}

/**
 * Manage a screen frames manipulation and stream.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::captureFromScreen()
{
    video_pipe_thread = new FeedVideoPipeThread();
    QObject::connect(video_pipe_thread, SIGNAL(notifyVideoToMstCondVar()),
                     this, SLOT(notifyVideoToMstCondVar()));
    video_pipe_thread->start();

    // Open mst pipes in write only mode.
    // Not really used to write inside the pipe
    if((mst_video_pipe = open(mstvideo_pipe_path.c_str(), O_WRONLY)) < 0)
    {
        std::cout << "Error opening MST video pipe\n";
    }

    while(thread_active)
    {
        // Define videochunk_out_path
        if(tik_tok)
        {
            Configurations::current_frame_path = "mst-temp/frames/tik";
            tik_tok = false;
        }
        else
        {
            Configurations::current_frame_path = "mst-temp/frames/tok";
            tik_tok = true;
        }

        // Take screen frame
        emit takeAScreenPicture();

        // Wait image to be ready
        sem_wait(&sem_picture);

        // Apply intrusion detection
        if(Configurations::intrusion_detection_enabled)
        {
            // Apply neural net on frame
            emit runIntrusionDetection(true);
            sem_wait(&sem_detection_done);
        }

        // Apply eventually resize and blur filtering
        if(Configurations::frame_size_changed ||
                Configurations::blur_effect != 0)
        {
            emit imageScaleBlur(Configurations::current_frame_path + "/output.bmp");
            sem_wait(&sem_picture);
        }

        // Wait for signal to start feeding mst video
        sem_wait(&sem_video);
        command = "bash -c \"cat " + Configurations::current_frame_path +
                "/output.bmp > " + mstvideo_pipe_path + "\"";
        std::system(command.c_str());
    }
}

/**
 * Init semaphores, makes directories on disk and start the production of
 * content choosed by the user.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::run()
{
    sem_init(&sem_audio, 0, 0);
    sem_init(&sem_video, 0, 0);
    sem_init(&sem_picture, 0, 0);
    sem_init(&sem_detection_done, 0, 0);
    sem_init(&sem_camera_frame, 0, 0);

    std::system("bash -c \"rm -R mst-temp\"");
    std::system("bash -c \"mkdir mst-temp\"");
    std::system("bash -c \"mkdir mst-temp/frames\"");
    std::system("bash -c \"mkdir mst-temp/frames/tik\"");
    std::system("bash -c \"mkdir mst-temp/frames/tok\"");
    std::system("bash -c \"mkdir mst-temp/audio\"");
    std::system("bash -c \"mkdir mst-temp/audio/tik\"");
    std::system("bash -c \"mkdir mst-temp/audio/tok\"");

    path = Configurations::execCmd("pwd");
    mstaudio_pipe_path = path + "/mst-temp/mst_audio_pipe";
    mstvideo_pipe_path = path + "/mst-temp/mst_video_pipe";
    ffaudio_pipe_path = path + "/mst-temp/ffmpeg_audio_pipe";
    ffvideo_pipe_path = path + "/mst-temp/ffmpeg_video_pipe";

    // Create mst-ffmpeg video and audio pipes

    mkfifo(mstvideo_pipe_path.c_str(), 0666);
    mkfifo(ffvideo_pipe_path.c_str(), 0666);
    if(Configurations::source_choices[Configurations::source] == "Video file")
    {
        mkfifo(mstaudio_pipe_path.c_str(), 0666);
        mkfifo(ffaudio_pipe_path.c_str(), 0666);
    }

    server_stream_thread = new ServerStreamThread();
    server_stream_thread->start();

    if(Configurations::intrusion_detection_enabled)
    {
        cuda_detection_thread = new CudaDetectionThread();
        QObject::connect(this, SIGNAL(runIntrusionDetection(bool)),
                         cuda_detection_thread,
                         SLOT(runIntrusionDetection(bool)));
        QObject::connect(cuda_detection_thread, SIGNAL(detectionDone()),
                         this, SLOT(detectionDone()));
        cuda_detection_thread->start();
    }

    if(Configurations::source_choices[Configurations::source] == "Video file")
    {
        captureFromFile();
    }
    else
    if(Configurations::source_choices[Configurations::source] == "Camera")
    {
        captureFromCamera();
    }
    else
    if(Configurations::source_choices[Configurations::source] == "Screen")
    {
        captureFromScreen();
    }
}

/**
 * Called when a screen picture is taked and stored on disk.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::pictureReady()
{
    sem_post(&sem_picture);
}

/**
 * Audio chunk could be pushed inside the productor pipe.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::notifyAudioToMstCondVar()
{
    sem_post(&sem_audio);
}

/**
 * Video chunk could be pushed inside the productor pipe.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::notifyVideoToMstCondVar()
{
    sem_post(&sem_video);
}

/**
 * Intrusion detection on frame(/s) applied and written changes to disk.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::detectionDone()
{
    sem_post(&sem_detection_done);
}

/**
 * Called when a camera picture is taked and stored on disk.
 * @param   : void.
 * @return  : void.
*/
void CameraThread::cameraFrameSaved()
{
    sem_post(&sem_camera_frame);
}
