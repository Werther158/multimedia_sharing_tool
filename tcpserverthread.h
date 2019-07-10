#ifndef TCPSERVERTHREAD_H
#define TCPSERVERTHREAD_H

#include <connectivity.h>
#include <configurations.h>
#include <QThread>

class TcpServerThread : public QThread
{
    Q_OBJECT
private:
    Connectivity *c;
public:
    TcpServerThread();
    void setConnectivity(Connectivity *c);
    void run();
signals:
    void writeText(QString);
    void clientConnected();
    void otherGuyDisconnected();
    void startServerStream();
};

#endif // TCPSERVERTHREAD_H
