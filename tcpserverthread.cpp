#include "tcpserverthread.h"

TcpServerThread::TcpServerThread()
{
}

void TcpServerThread::setConnectivity(Connectivity *c)
{
    this->c = c;
}

void TcpServerThread::run()
{
    connect(c, SIGNAL(writeText(QString)), this, SIGNAL(writeText(QString)));
    connect(c, SIGNAL(startServerStream()), this, SIGNAL(startServerStream()));
    connect(c, SIGNAL(clientConnected()), this, SIGNAL(clientConnected()));
    connect(c, SIGNAL(otherGuyDisconnected()), this, SIGNAL(otherGuyDisconnected()));
    (*c).tcpServer(Configurations::port);
}
