#include "feedaudiopipethread.h"

FeedAudioPipeThread::FeedAudioPipeThread()
{
    path = execCmd("pwd");
    mstaudio_pipe_path = path + "/mst-temp/mst_audio_pipe";
    ffaudio_pipe_path = path + "/mst-temp/ffmpeg_audio_pipe";
}

FeedAudioPipeThread::~FeedAudioPipeThread()
{

}

std::string FeedAudioPipeThread::execCmd(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    auto pipe = popen(cmd, "r");

    if (!pipe) throw std::runtime_error("popen() failed!");

    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != nullptr)
            result += buffer.data();
    }

    pclose(pipe);

    result.pop_back(); // remove \n character
    return result;
}

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
