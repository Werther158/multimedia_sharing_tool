//_____________________________________________________________________________
//_____________________________________________________________________________
//                                CLIENT STREAM THREAD
// Allows the client to receive a video stream.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "clientstreamthread.h"

ClientStreamThread::ClientStreamThread()
{

}

ClientStreamThread::~ClientStreamThread()
{
    int ret;
    std::string command;
    command = "bash -c \"fuser -k " +
            std::to_string(Configurations::port + 1) + "/tcp\"";
    ret = std::system(command.c_str());
    if(ret == -1)
        std::cout << "std::system returned -1\n";
    quit();
    wait();
}

/**
 * Start RTSP receiver; calling FFplay.
 * @param   : void.
 * @return  : void.
*/
void ClientStreamThread::run()
{
    int ret;
    emit sendStartStreamingCommand();
    std::string command;
    ret = std::system("bash -c \"killall ibus-daemon\"");
    if(ret == -1)
        std::cout << "std::system returned -1\n";

    command = "bash -c \"ffplay -window_title 'MST Streaming' "
              "-rtsp_flags listen rtsp://" + Configurations::server_ip + "@"
            + Configurations::my_own_used_ip + ":" +
            std::to_string(Configurations::port + 1) + "\"";

    ret = std::system(command.c_str());
    if(ret == -1)
        std::cout << "std::system returned -1\n";

    emit streamingEnded();
}
