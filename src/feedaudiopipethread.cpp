//_____________________________________________________________________________
//_____________________________________________________________________________
//                             FEED AUDIO PIPE THREAD
// Bridge that connects Camera Thread to FFmpeg process, receiving audio from a
// camera pipe and forwarding it to an ffmpeg pipe.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "feedaudiopipethread.h"

FeedAudioPipeThread::FeedAudioPipeThread()
{
    thread_active = true;
    path = Configurations::execCmd("pwd");
    mstaudio_pipe_path = path + "/mst-temp/mst_audio_pipe";
    ffaudio_pipe_path = path + "/mst-temp/ffmpeg_audio_pipe";
}

FeedAudioPipeThread::~FeedAudioPipeThread()
{
    close(mst_audio_pipe);
    close(ffmpeg_audio_pipe);
    terminate();
    wait();
}

/**
 * Start a routine that continuosly collect audio data from mst_audio_pipe and
 * forward it to ffmpeg_audio_pipe.
 * @param   : void.
 * @return  : void.
*/
void FeedAudioPipeThread::run()
{
    if((mst_audio_pipe = open(mstaudio_pipe_path.c_str(), O_RDONLY)) < 0)
    {
        std::cout << "Error opening MST audio pipe\n";
    }

    if((ffmpeg_audio_pipe = open(ffaudio_pipe_path.c_str(), O_WRONLY)) < 0)
    {
        std::cout << "Error opening FFmpeg audio pipe\n";
    }

    while(true)
    {
        // Emit write to mst audio pipe signal
        emit notifyAudioToMstCondVar();

        count = read(mst_audio_pipe, buffer, 100000);
        if(count == -1)
        {
            std::cout << "Error reading mst_audio_pipe";
            break;
        }

        count = write(ffmpeg_audio_pipe, buffer, static_cast<size_t>(count));
        if(count == -1)
        {
            std::cout << "Error writing ffmpeg_audio_pipe";
            break;
        }
    }

    close(mst_audio_pipe);
    close(ffmpeg_audio_pipe);
}
