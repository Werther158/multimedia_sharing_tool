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
    std::string command = "bash -c \"fuser -k " + std::to_string(Configurations::port + 1) + "/tcp\"";
    std::system(command.c_str());
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
    emit sendStartStreamingCommand();
    std::string command;
    std::system("bash -c \"killall ibus-daemon\"");

    command = "bash -c \"ffplay -window_title 'MST Streaming' -rtsp_flags listen rtsp://" +
            Configurations::server_ip + "@" + Configurations::my_own_used_ip + ":" + std::to_string(Configurations::port + 1) + "\"";

    std::system(command.c_str());
    emit streamingEnded();
}
