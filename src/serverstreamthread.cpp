//_____________________________________________________________________________
//_____________________________________________________________________________
//                             SERVER STREAM THREAD
// Allows the server to send an audio and video stream to the client.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "serverstreamthread.h"

ServerStreamThread::ServerStreamThread()
{
}

ServerStreamThread::~ServerStreamThread()
{
    terminate();
    wait();
}

/**
 * Start RTSP transmitter; calling FFmpeg.
 * @param   : void.
 * @return  : void.
*/
void ServerStreamThread::run()
{
    std::string command, frame_size, color_scale;

    // Sleep 3 seconds to allow Client to start listening correctly
    sleep(3);

    path = Configurations::execCmd("pwd");
    rtsp_url = "rtsp://" + Configurations::my_own_used_ip + "@" +
            Configurations::client_ip + ":" +
            std::to_string(Configurations::port + 1);

    ffvideo_pipe_path = path + "/mst-temp/ffmpeg_video_pipe";

    frame_size = "";

    if(Configurations::frame_size_changed)
    {
        frame_size += "-s ";
        frame_size += std::to_string(Configurations::frame_width);
        frame_size += "x";
        frame_size += std::to_string(Configurations::frame_height);
        frame_size += " ";
    }

    switch(Configurations::color_scale_choices[Configurations::color_scale])
    {
    case 24:
        color_scale = "-pix_fmt rgb24";
        break;
    case 16:
        color_scale = "-pix_fmt yuv422p";
        break;
    case 15:
        color_scale = "-pix_fmt rgb555be";
        break;
    case 8:
        color_scale = "-pix_fmt rgb8";
        break;
    case 4:
        color_scale = "-pix_fmt rgb4";
        break;
    case 1:
        color_scale = "-pix_fmt monow";
        break;
    default:
        color_scale = "";
        break;
    }

    if(Configurations::source_choices[Configurations::source] == "Video file")
    {
        ffaudio_pipe_path = path + "/mst-temp/ffmpeg_audio_pipe";

        command = "ffmpeg -probesize 2147483647 " + frame_size
                 + color_scale + " -i " + ffvideo_pipe_path + " -i " +
                ffaudio_pipe_path + " -vsync 1";

        if(Configurations::fps_choices[Configurations::fps] != -1)
        {
            command += " -r " + std::to_string
                   (Configurations::fps_choices[Configurations::fps]);
        }
        command += " -vcodec libx264 -crf 23 -preset ultrafast"
                   " -f rtsp -rtsp_transport tcp " + rtsp_url;

    }
    else
    {
        command = "ffmpeg -re " + frame_size + color_scale + " -i " +
                ffvideo_pipe_path;
        if(Configurations::fps_choices[Configurations::fps] != -1)
        {
            command += " -r " + std::to_string
                    (Configurations::fps_choices[Configurations::fps]);
        }
        command += " -vcodec libx264 -crf 23 "
                   "-preset ultrafast -f rtsp -rtsp_transport tcp " + rtsp_url;
    }

    // Activate ffmpeg streaming command
    std::system(command.c_str());
}

/**
 * Set streaming ended at true.
 * @param   : void.
 * @return  : void.
*/
void ServerStreamThread::setStreamingEnded()
{
    streaming_ended = true;
}
