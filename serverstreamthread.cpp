#include "serverstreamthread.h"

ServerStreamThread::ServerStreamThread()
{
}

ServerStreamThread::~ServerStreamThread()
{
    std::system("killall ffmpeg");
    quit();
    wait();
}

void ServerStreamThread::run()
{
    std::string command;
    command = "ffmpeg -i " + Configurations::file_name + " -c copy " + Configurations::file_name +"_fixed.mkv";
    std::system(command.c_str());
    command = "rm " + Configurations::file_name;
    std::system(command.c_str());
    command = "mv " + Configurations::file_name +"_fixed.mkv" + " " + Configurations::file_name;
    std::system(command.c_str());
    command = "ffmpeg -re -i " + Configurations::file_name + " -c copy -f matroska udp://" +
            Configurations::client_ip + ":" + std::to_string(Configurations::port);
    std::system(command.c_str());
}
