#include "serverstreamthread.h"

ServerStreamThread::ServerStreamThread()
{
}

ServerStreamThread::~ServerStreamThread()
{
    std::system("bash -c \"killall ffmpeg\"");
    std::string command = "bash -c \"fuser -k " + std::to_string(Configurations::port) + "/udp\"";
    std::system(command.c_str());
    quit();
    wait();
}

void ServerStreamThread::run()
{
    std::string command;
    command = "bash -c \"ffmpeg -i " + Configurations::file_name + " -c copy " + Configurations::file_name +"_fixed.mkv\"";
    std::system(command.c_str());
    command = "bash -c \"rm " + Configurations::file_name + "\"";
    std::system(command.c_str());
    command = "bash -c \"mv " + Configurations::file_name +"_fixed.mkv" + " " + Configurations::file_name + "\"";
    std::system(command.c_str());
    // Sleep 3 seconds to allow Client to start listening correctly
    sleep(3);
    command = "bash -c \"ffmpeg -re -i " + Configurations::file_name + " -c copy -f matroska udp://" +
            Configurations::client_ip + ":" + std::to_string(Configurations::port) + "\"";
    std::system(command.c_str());
    emit stopStream();
}
