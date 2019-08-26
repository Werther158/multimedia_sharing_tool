//_____________________________________________________________________________
//_____________________________________________________________________________
//                             FEED VIDEO PIPE THREAD
// Bridge that connects Camera Thread to FFmpeg process, receiving video from a
// camera pipe and forwarding it to an ffmpeg pipe.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "feedvideopipethread.h"

FeedVideoPipeThread::FeedVideoPipeThread()
{
    thread_active = true;
    path = Configurations::execCmd("pwd");
    mstvideo_pipe_path = path + "/mst-temp/mst_video_pipe";
    ffvideo_pipe_path = path + "/mst-temp/ffmpeg_video_pipe";
}

FeedVideoPipeThread::~FeedVideoPipeThread()
{
    close(mst_video_pipe);
    close(ffmpeg_video_pipe);
    terminate();
    wait();
}

/**
 * Start a routine that continuosly collect video data from mst_video_pipe and
 * forward it to ffmpeg_video_pipe.
 * @param   : void.
 * @return  : void.
*/
void FeedVideoPipeThread::run()
{
    if((mst_video_pipe = open(mstvideo_pipe_path.c_str(), O_RDONLY)) < 0)
    {
        std::cout << "Error opening MST video pipe\n";
    }

    if((ffmpeg_video_pipe = open(ffvideo_pipe_path.c_str(), O_WRONLY)) < 0)
    {
        std::cout << "Error opening FFmpeg video pipe\n";
    }

    while(true)
    {
        // Emit write to mst video pipe signal
        emit notifyVideoToMstCondVar();

        count = read(mst_video_pipe, buffer, 100000);
        if(count == -1)
        {
            break;
        }

        count = write(ffmpeg_video_pipe, buffer, static_cast<size_t>(count));
        if(count == -1)
        {
            break;
        }
    }

    close(mst_video_pipe);
    close(ffmpeg_video_pipe);
}
