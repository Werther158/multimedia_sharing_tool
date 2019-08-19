#include "feedvideopipethread.h"

FeedVideoPipeThread::FeedVideoPipeThread()
{
    path = execCmd("pwd");
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

std::string FeedVideoPipeThread::execCmd(const char* cmd)
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
