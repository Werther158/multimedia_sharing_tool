#ifndef FEEDVIDEOPIPETHREAD_H
#define FEEDVIDEOPIPETHREAD_H

#include <QThread>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <configurations.h>

class FeedVideoPipeThread : public QThread
{
    Q_OBJECT
private:
    std::string path, mstvideo_pipe_path, ffvideo_pipe_path;
    int mst_video_pipe, ffmpeg_video_pipe;
    bool thread_active;
    char buffer[100000];
    ssize_t count;

public:
    FeedVideoPipeThread();
    ~FeedVideoPipeThread();
    void run();

signals:
    void notifyVideoToMstCondVar();
};

#endif // FEEDVIDEOPIPETHREAD_H
