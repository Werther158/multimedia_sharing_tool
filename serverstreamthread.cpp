#include "serverstreamthread.h"

ServerStreamThread::ServerStreamThread()
{
}

ServerStreamThread::~ServerStreamThread()
{
    std::system("bash -c \"killall ffmpeg\"");
    std::string command = "bash -c \"fuser -k " + std::to_string(Configurations::port + 1) + "/tcp\"";
    std::system(command.c_str());
    quit();
    wait();
}

void ServerStreamThread::run()
{
    std::string command;
    // Sleep 3 seconds to allow Client to start listening correctly
    sleep(3);
    if(Configurations::client_ip != Configurations::my_own_used_ip)
        command = "bash -c \"ffmpeg -re -y -i " + Configurations::file_name + " -codec copy -acodec libmp3lame -f rtsp -rtsp_transport tcp rtsp://" +
                Configurations::my_own_used_ip + "@" + Configurations::client_ip + ":" + std::to_string(Configurations::port + 1) + "\"";
    else
        command = "bash -c \"ffmpeg -re -y -i " + Configurations::file_name + " -codec copy -acodec libmp3lame -f rtsp -rtsp_transport tcp rtsp://" +
                Configurations::client_ip + ":" + std::to_string(Configurations::port + 1) + "\"";
    std::system(command.c_str());
    sleep(3);
    if(!streaming_ended)
        emit stopStream();
}

void ServerStreamThread::setStreamingEnded()
{
    streaming_ended = true;
}
