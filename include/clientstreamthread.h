#ifndef CLIENTSTREAMTHREAD_H
#define CLIENTSTREAMTHREAD_H

#include "connectivity.h"
#include <QThread>

class ClientStreamThread : public QThread
{
    Q_OBJECT
public:
    ClientStreamThread();
    ~ClientStreamThread();
    void run();
signals:
    void sendStartStreamingCommand();
    void streamingEnded();
};

#endif // CLIENTSTREAMTHREAD_H
