#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <stdlib.h>
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core/core.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#undef Bool
#undef CursorShape
#undef Expose
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut
#undef FontChange
#undef None
#undef Status
#undef Unsorted

#define SERVER 0
#define CLIENT 1

class Configurations
{
public:
    Configurations();
    static std::string execCmd(const char* cmd);

    static std::string source_choices[];
    static std::string resolution_choices[];
    static int fps_choices[];
    static int color_scale_choices[];

    static uint8_t system;
    static uint8_t source;
    static std::string server_ip;
    static std::string client_ip;
    // My Ip used to connect to Server or Client
    static std::string my_own_used_ip;
    static uint16_t port;
    static std::string password;
    static bool leave_client_config;
    static uint8_t resolution;
    static uint8_t fps;
    static uint8_t color_scale;

    // Streaming utils
    static uint8_t video_chunk_seconds;
    static std::string file_name;
    static std::string camera_path;
    static std::string current_frame_path;
    static std::string current_audio_path;
    static cv::Rect2d rect; // Rectangle for the ROI
    static int frame_width;
    static int frame_height;

    // Neural network utils
    static bool intrusion_detection_enabled;
    static std::string network; // Defines the tipe of network to use

};

/**
 * Defines a screen screenshot.
*/
struct ScreenShot
{
    Display* display;
    Window root;
    int x,y,width,height;
    XImage* img;
    bool init;

    ScreenShot(int x, int y, int width, int height):
        x(x),
        y(y),
        width(width),
        height(height)
    {
        display = XOpenDisplay(nullptr);
        root = DefaultRootWindow(display);

        init = true;
    }

    void operator() (cv::Mat& cvImg)
    {
        if (init == true)
            init = false;
        else
            XDestroyImage(img);

        img = XGetImage(display, root, x, y, width, height,
                        AllPlanes, ZPixmap);

        cvImg = cv::Mat(height, width, CV_8UC4, img->data);
    }

    ~ScreenShot()
    {
        if (init == false)
            XDestroyImage(img);

        XCloseDisplay(display);
    }
};

#endif // CONFIGURATIONS_H
