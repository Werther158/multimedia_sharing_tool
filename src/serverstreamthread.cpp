//_____________________________________________________________________________
//_____________________________________________________________________________
//                             SERVER STREAM THREAD
// Allows the server to send an audio and video stream to the client.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "serverstreamthread.h"

ServerStreamThread::ServerStreamThread()
{
}

ServerStreamThread::~ServerStreamThread()
{
    terminate();
    wait();
}

/**
 * Start RTSP transmitter; calling FFmpeg.
 * @param   : void.
 * @return  : void.
*/
void ServerStreamThread::run()
{
    std::string command, frame_size;

    // Sleep 3 seconds to allow Client to start listening correctly
    sleep(3);

    path = Configurations::execCmd("pwd");
    rtsp_url = "rtsp://" + Configurations::my_own_used_ip + "@" +
            Configurations::client_ip + ":" +
            std::to_string(Configurations::port + 1);

    ffvideo_pipe_path = path + "/mst-temp/ffmpeg_video_pipe";

    if(Configurations::source_choices[Configurations::source] == "Video file")
    {
        ffaudio_pipe_path = path + "/mst-temp/ffmpeg_audio_pipe";
        command = "ffmpeg -probesize 2147483647 -s 1280x720 -pix_fmt rgb24 -i "
                + ffvideo_pipe_path + " -i " + ffaudio_pipe_path +
                " -vsync 1 -r 25 -vcodec libx264 -crf 23 -preset ultrafast"
                " -f rtsp -rtsp_transport tcp " + rtsp_url;
    }
    else
    {
        frame_size = "";
        frame_size += std::to_string(Configurations::frame_width);
        frame_size += "x";
        frame_size += std::to_string(Configurations::frame_height);
        command = "ffmpeg -re -s " + frame_size + " -pix_fmt rgb24 -i " +
                ffvideo_pipe_path + " -r 60 -vcodec libx264 -crf 23 "
                "-preset ultrafast -f rtsp -rtsp_transport tcp " + rtsp_url;
    }

    // Activate ffmpeg streaming command
    std::system(command.c_str());
}

/**
 * Set streaming ended at true.
 * @param   : void.
 * @return  : void.
*/
void ServerStreamThread::setStreamingEnded()
{
    streaming_ended = true;
}
