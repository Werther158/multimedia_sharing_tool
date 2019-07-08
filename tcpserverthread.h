#ifndef TCPSERVERTHREAD_H
#define TCPSERVERTHREAD_H

#include <connectivity.h>
#include <configurations.h>
#include <QThread>

class TcpServerThread : public QThread
{
    Q_OBJECT
public:
    TcpServerThread();
    void run();
signals:
    void writeText(QString);
};

#endif // TCPSERVERTHREAD_H
