//_____________________________________________________________________________
//_____________________________________________________________________________
//                             TCP CLIENT THREAD
// Used by the client to maintain opened a connection with the server;
// constantely listening for new messages.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "tcpclientthread.h"

TcpClientThread::TcpClientThread()
{
}

/**
 * Set current connectivity object in use.
 * @param   : void.
 * @return  : void.
*/
void TcpClientThread::setConnectivity(Connectivity *c)
{
    this->c = c;
}

/**
 * Start client thread, allowing connection with the server.
 * @param   : void.
 * @return  : void.
*/
void TcpClientThread::run()
{
    connect(c, SIGNAL(writeText(QString)), this, SIGNAL(writeText(QString)));
    connect(c, SIGNAL(clientConnected()), this, SIGNAL(clientConnected()));
    connect(c, SIGNAL(otherGuyDisconnected()), this,
            SIGNAL(otherGuyDisconnected()));
    connect(c, SIGNAL(stopReceivingVideoStream(bool)),
            this, SIGNAL(stopReceivingVideoStream(bool)));
    connect(c, SIGNAL(startStreaming()), this, SIGNAL(startStreaming()));
    connect(c, SIGNAL(updateListConfigurations()),
            this, SIGNAL(updateListConfigurations()));
    (*c).tcpClient(Configurations::server_ip, Configurations::port);
}
