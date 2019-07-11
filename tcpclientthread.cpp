#include "tcpclientthread.h"

TcpClientThread::TcpClientThread()
{
}

void TcpClientThread::setConnectivity(Connectivity *c)
{
    this->c = c;
}

void TcpClientThread::run()
{
    connect(c, SIGNAL(writeText(QString)), this, SIGNAL(writeText(QString)));
    connect(c, SIGNAL(clientConnected()), this, SIGNAL(clientConnected()));
    connect(c, SIGNAL(otherGuyDisconnected()), this, SIGNAL(otherGuyDisconnected()));
    connect(c, SIGNAL(stopReceivingVideoStream(bool)), this, SIGNAL(stopReceivingVideoStream(bool)));
    (*c).tcpClient(Configurations::server_ip, Configurations::port);
}
