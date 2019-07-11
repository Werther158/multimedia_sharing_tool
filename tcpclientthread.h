#ifndef TCPCLIENTTHREAD_H
#define TCPCLIENTTHREAD_H

#include <connectivity.h>
#include <configurations.h>
#include <QThread>

class TcpClientThread : public QThread
{
    Q_OBJECT
private:
    Connectivity *c;
public:
    TcpClientThread();
    void setConnectivity(Connectivity *c);
    void run();
signals:
    void writeText(QString);
    void clientConnected();
    void otherGuyDisconnected();
    void stopReceivingVideoStream(bool);
};

#endif // TCPCLIENTTHREAD_H
