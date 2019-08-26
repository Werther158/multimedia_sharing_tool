//_____________________________________________________________________________
//_____________________________________________________________________________
//                             TCP SERVER THREAD
// Used by the server to maintain opened a connection with the client;
// constantely listening for new messages.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "tcpserverthread.h"

TcpServerThread::TcpServerThread()
{
}

/**
 * Set current connectivity object in use.
 * @param   : void.
 * @return  : void.
*/
void TcpServerThread::setConnectivity(Connectivity *c)
{
    this->c = c;
}

/**
 * Start server thread, allowing connection with the client.
 * @param   : void.
 * @return  : void.
*/
void TcpServerThread::run()
{
    connect(c, SIGNAL(writeText(QString)), this, SIGNAL(writeText(QString)));
    connect(c, SIGNAL(startServerStream()), this, SIGNAL(startServerStream()));
    connect(c, SIGNAL(clientConnected()), this, SIGNAL(clientConnected()));
    connect(c, SIGNAL(otherGuyDisconnected()),
            this, SIGNAL(otherGuyDisconnected()));
    connect(c, SIGNAL(streamingEnded()), this, SIGNAL(streamingEnded()));
    (*c).tcpServer(Configurations::port);
}
