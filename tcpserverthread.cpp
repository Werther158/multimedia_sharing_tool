#include "tcpserverthread.h"

TcpServerThread::TcpServerThread()
{
}

void TcpServerThread::run()
{
    Connectivity c;
    connect(&c, SIGNAL(writeText(QString)), this, SIGNAL(writeText(QString)));
    c.tcpServer(Configurations::port);
}
