#ifndef FEEDVIDEOPIPETHREAD_H
#define FEEDVIDEOPIPETHREAD_H

#include <QThread>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

class FeedVideoPipeThread : public QThread
{
    Q_OBJECT
private:
    std::string path, mstvideo_pipe_path, ffvideo_pipe_path;
    int mst_video_pipe, ffmpeg_video_pipe;
    std::mutex mtx;
    std::condition_variable cond_var;
    bool thread_active = true;
    char buffer[100000];
    ssize_t count;

    std::string execCmd(const char* cmd);

public:
    FeedVideoPipeThread();
    ~FeedVideoPipeThread();
    void run();

signals:
    void notifyVideoToMstCondVar();
};

#endif // FEEDVIDEOPIPETHREAD_H
