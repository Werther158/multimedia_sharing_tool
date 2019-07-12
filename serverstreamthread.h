#ifndef SERVERSTREAMTHREAD_H
#define SERVERSTREAMTHREAD_H

#include <configurations.h>
#include <QThread>

class ServerStreamThread : public QThread
{
    Q_OBJECT
private:
    bool streaming_ended = false;
public:
    ServerStreamThread();
    ~ServerStreamThread();
    void run();
public slots:
    void setStreamingEnded();

signals:
    void writeText(QString);
    void stopStream();
};

#endif // SERVERSTREAMTHREAD_H
