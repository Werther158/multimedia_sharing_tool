#ifndef FEEDAUDIOPIPETHREAD_H
#define FEEDAUDIOPIPETHREAD_H

#include "configurations.h"
#include <QThread>
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

class FeedAudioPipeThread : public QThread
{
    Q_OBJECT
private:
    std::string path, mstaudio_pipe_path, ffaudio_pipe_path;
    int mst_audio_pipe, ffmpeg_audio_pipe;
    bool thread_active;
    char buffer[100000];
    ssize_t count;

public:
    FeedAudioPipeThread();
    ~FeedAudioPipeThread();
    void run();

signals:
    void notifyAudioToMstCondVar();
};

#endif // FEEDAUDIOPIPETHREAD_H
