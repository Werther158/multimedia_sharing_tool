#ifndef SERVERSTREAMTHREAD_H
#define SERVERSTREAMTHREAD_H

#include <configurations.h>
#include <QThread>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

class ServerStreamThread : public QThread
{
    Q_OBJECT
private:
    std::string path, ffvideo_pipe_path, ffaudio_pipe_path, rtsp_url;
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
