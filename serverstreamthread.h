#ifndef SERVERSTREAMTHREAD_H
#define SERVERSTREAMTHREAD_H

#include <configurations.h>
#include <QThread>

class ServerStreamThread : public QThread
{
    Q_OBJECT
public:
    ServerStreamThread();
    ~ServerStreamThread();
    void run();
signals:
    void writeText(QString);
};

#endif // SERVERSTREAMTHREAD_H
