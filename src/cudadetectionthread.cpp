#include "cudadetectionthread.h"

CudaDetectionThread::CudaDetectionThread()
{
    imgCPU    = nullptr;
    imgCUDA   = nullptr;
    imgWidth  = 0;
    imgHeight = 0;
    detection_running = true;
}

CudaDetectionThread::~CudaDetectionThread()
{
//    detection_running = false;
//    sem_post(&sem_run);
    terminate();
    wait();
    /*
     * destroy resources
     */
    SAFE_DELETE(net);
    CUDA(cudaFreeHost(imgCPU));
}

void CudaDetectionThread::run()
{
    sem_init(&sem_run, 0, 0);

    std::string file_path;
    int argc = 4;

    file_path = Configurations::current_frame_path + "/output.bmp";
    char *argv[] = {"./", "--network=ssd-mobilenet-v2", (char*)file_path.c_str(), (char*)file_path.c_str()};

    /*
     * create detection network
     */
    net = detectNet::Create(argc, argv);

    if( !net )
    {
        printf("detectnet-console:   failed to initialize detectNet\n");
        return;
    }

    while(detection_running)
    {
        sem_wait(&sem_run);

        file_path = Configurations::current_frame_path + "/output.bmp";
        if( !loadImageRGBA(file_path.c_str(), (float4**)&imgCPU, (float4**)&imgCUDA, &imgWidth, &imgHeight) )
        {
            printf("failed to load image '%s'\n", file_path.c_str());
            return;
        }

        /*
         * detect objects in image
         */
        detectNet::Detection* detections = nullptr;

        net->Detect(imgCUDA, static_cast<uint32_t>(imgWidth), static_cast<uint32_t>(imgHeight), &detections);

        // wait for the GPU to finish
        CUDA(cudaDeviceSynchronize());

        if( !saveImageRGBA(file_path.c_str(), (float4*)imgCPU, imgWidth, imgHeight, 255.0f) )
            printf("detectnet-console:  failed saving %ix%i image to '%s'\n", imgWidth, imgHeight, file_path.c_str());

        emit detectionDone();
    }
}

void CudaDetectionThread::runIntrusionDetection()
{
    sem_post(&sem_run);
}
