#include "clientstreamthread.h"

ClientStreamThread::ClientStreamThread()
{

}

ClientStreamThread::~ClientStreamThread()
{
    std::string command = "fuser -k " + std::to_string(Configurations::port) + "/udp";
    std::system(command.c_str());
    quit();
    wait();
}

void ClientStreamThread::run()
{
    emit sendStartStreamingCommand();
    std::string command;
    std::system("killall ibus-daemon");
    command = "ffplay udp://" + Configurations::server_ip + ":" + std::to_string(Configurations::port);
    std::system(command.c_str());
    emit streamingEnded();
}
