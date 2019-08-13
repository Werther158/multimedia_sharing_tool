#include "serverstreamthread.h"

ServerStreamThread::ServerStreamThread()
{
}

ServerStreamThread::~ServerStreamThread()
{
}

std::string ServerStreamThread::execCmd(const char* cmd)
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

void ServerStreamThread::run()
{
    std::string command;

    // Sleep 3 seconds to allow Client to start listening correctly
    sleep(3);

    path = execCmd("pwd");
    ffvideo_pipe_path = path + "/mst-temp/ffmpeg_video_pipe";
    ffaudio_pipe_path = path + "/mst-temp/ffmpeg_audio_pipe";

    // Activate ffmpeg streaming command
    rtsp_url = "rtsp://" + Configurations::my_own_used_ip + "@" + Configurations::client_ip +
            ":" + std::to_string(Configurations::port + 1);
    command = "ffmpeg -probesize 2147483647 -s 1280x720 -pix_fmt rgb24 -i " + ffvideo_pipe_path + " -i " + ffaudio_pipe_path + " -vsync 1 -r 25 -vcodec libx264 -crf 23 -preset ultrafast -f rtsp -rtsp_transport tcp " + rtsp_url;
    std::system(command.c_str());
}

void ServerStreamThread::setStreamingEnded()
{
    streaming_ended = true;
}
