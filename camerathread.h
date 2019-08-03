#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QThread>
#include <configurations.h>

class CameraThread : public QThread
{
    Q_OBJECT
public:
    CameraThread();
    ~CameraThread();
    void run();
};

#endif // CAMERATHREAD_H
