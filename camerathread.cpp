#include "camerathread.h"

CameraThread::CameraThread()
{

}

CameraThread::~CameraThread()
{

}

void CameraThread::run()
{
    if(Configurations::source_choices[Configurations::source] == "Video file")
    {
        //captureFromFile();
    }
    else
    if(Configurations::source_choices[Configurations::source] == "Camera")
    {
        //captureFromCamera();
    }
    else
    if(Configurations::source_choices[Configurations::source] == "Screen")
    {
        //captureFromScreen();
    }
}
