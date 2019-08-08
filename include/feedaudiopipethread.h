#ifndef FEEDAUDIOPIPETHREAD_H
#define FEEDAUDIOPIPETHREAD_H

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
    std::mutex mtx;
    std::condition_variable cond_var;
    bool thread_active = true;
    char buffer[100000];
    ssize_t count;

    std::string execCmd(const char* cmd);
public:
    FeedAudioPipeThread();
    ~FeedAudioPipeThread();
    void run();

signals:
    void notifyAudioToMstCondVar();
};

#endif // FEEDAUDIOPIPETHREAD_H
