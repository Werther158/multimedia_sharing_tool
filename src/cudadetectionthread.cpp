//_____________________________________________________________________________
//_____________________________________________________________________________
//                                CUDA DETECTION THREAD
// Runs the Intrusion detection using a Neural network.
//_____________________________________________________________________________
//_____________________________________________________________________________

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
    terminate();
    wait();
    /*
     * destroy resources
     */
    SAFE_DELETE(net);
    CUDA(cudaFreeHost(imgCPU));
}

/**
 * Using cuda, apply intrusion detection using the neural network.
 * @param   : file_path; path of the frame to use.
 * @return  : void.
*/
void CudaDetectionThread::detectOnImage(std::string file_path)
{
    if( !loadImageRGBA(file_path.c_str(), reinterpret_cast<float4**>(&imgCPU),
                       reinterpret_cast<float4**>(&imgCUDA), &imgWidth, &imgHeight) )
    {
        printf("failed to load image '%s'\n", file_path.c_str());
        return;
    }

    /*
     * detect objects in image
     */
    detectNet::Detection* detections;
    detections = nullptr;

    net->Detect(imgCUDA, static_cast<uint32_t>
                (imgWidth), static_cast<uint32_t>(imgHeight), &detections);

    // wait for the GPU to finish
    CUDA(cudaDeviceSynchronize());

    if(!saveImageRGBA(file_path.c_str(), reinterpret_cast<float4*>(imgCPU),
                      imgWidth, imgHeight, 255.0f))
        printf("detectnet-console:  failed saving %ix%i image to '%s'\n",
               imgWidth, imgHeight, file_path.c_str());
}

/**
 * Initialize the network and semaphores and start detection routine.
 * @param   : void.
 * @return  : void.
*/
void CudaDetectionThread::run()
{
    sem_init(&sem_run, 0, 0);

    std::string file_path, network;
    int argc;

    argc = 4;
    network = "--network=";
    network += Configurations::network;

    file_path = Configurations::current_frame_path + "/output.bmp";
    char *argv[] = {const_cast<char*>("./"),
                    const_cast<char*>(network.c_str()),
                    const_cast<char*>(file_path.c_str()),
                    const_cast<char*>(file_path.c_str())};

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

        if(single_frame)
        {
            // Elaborate a single frame
            file_path = Configurations::current_frame_path + "/output.bmp";
            detectOnImage(file_path);
        }
        else
        {
            // Elaborate all chunk frames
            QDir directory(QString::fromStdString
                           (Configurations::current_frame_path));
            QStringList images = directory.entryList
                    (QStringList() << "*.bmp", QDir::Files);
            foreach(QString filename, images) {
                detectOnImage(Configurations::current_frame_path
                              + "/" + filename.toStdString());
            }
        }

        emit detectionDone();
    }
}

/**
 * Gives the signal at the thread to start detection on frame.
 * @param   : single_frame; true if detection has to be done on a single frame,
 *            false otherwise.
 * @return  : void.
*/
void CudaDetectionThread::runIntrusionDetection(bool single_frame)
{
    this->single_frame = single_frame;
    sem_post(&sem_run);
}
