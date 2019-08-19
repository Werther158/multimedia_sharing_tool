#ifndef CUDADETECTIONTHREAD_H
#define CUDADETECTIONTHREAD_H

#include <QThread>
#include <jetson-inference/detectNet.h>
#include <jetson-utils/loadImage.h>
#include <jetson-utils/cudaMappedMemory.h>
#include <semaphore.h>
#include <configurations.h>
#include <QDir>

class CudaDetectionThread : public QThread
{
    Q_OBJECT
private:
    sem_t sem_run;
    bool detection_running, single_frame;
    /*
     * Intrusion detection variables
     */
    float* imgCPU;
    float* imgCUDA;
    int    imgWidth;
    int    imgHeight;
    detectNet* net;

    void detectOnImage(std::string file_path);

public:
    CudaDetectionThread();
    ~CudaDetectionThread();
    void run();

public slots:
    void runIntrusionDetection(bool single_frame);

signals:
    void detectionDone();
};

#endif // CUDADETECTIONTHREAD_H
