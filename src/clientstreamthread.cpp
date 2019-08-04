#include "clientstreamthread.h"

ClientStreamThread::ClientStreamThread()
{

}

ClientStreamThread::~ClientStreamThread()
{
    std::string command = "bash -c \"fuser -k " + std::to_string(Configurations::port + 1) + "/tcp\"";
    std::system(command.c_str());
    quit();
    wait();
}

void ClientStreamThread::run()
{
    emit sendStartStreamingCommand();
    std::string command;
    std::system("bash -c \"killall ibus-daemon\"");
    if(Configurations::server_ip != Configurations::my_own_used_ip)
        command = "bash -c \"ffplay -window_title 'MST Streaming' -rtsp_flags listen rtsp://" +
                Configurations::server_ip + "@" + Configurations::my_own_used_ip + ":" + std::to_string(Configurations::port + 1) + "\"";
    else
        command = "bash -c \"ffplay -window_title 'MST Streaming' -rtsp_flags listen rtsp://" +
                Configurations::server_ip + ":" + std::to_string(Configurations::port + 1) + "\"";
    std::system(command.c_str());
    emit streamingEnded();
}
