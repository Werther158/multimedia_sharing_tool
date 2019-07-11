#include "clientstreamthread.h"

ClientStreamThread::ClientStreamThread()
{

}

ClientStreamThread::~ClientStreamThread()
{
    std::system("killall ffplay");
    quit();
    wait();
}

void ClientStreamThread::run()
{
    emit sendStartStreamingCommand();
    std::string command;
    command = "ffplay udp://" + Configurations::server_ip + ":" + std::to_string(Configurations::port);
    std::system(command.c_str());
    emit streamingEnded();
}
