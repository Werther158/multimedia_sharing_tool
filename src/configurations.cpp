//_____________________________________________________________________________
//_____________________________________________________________________________
//                                CONFIGURATIONS
// Collection of static variables needed by the applications usually configured
// by the user.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "configurations.h"

using namespace std;

std::string Configurations::source_choices[] = {"Video file",
                                                "Camera", "Screen"};
std::string Configurations::resolution_choices[] = {"Source", "3840 x 2160",
                                   "2560 x 1440", "1920 x 1080", "1600 x 900",
                                   "1280 x 720", "854 x 480", "640 x 360",
                                                    "426 x 240", "256 x 144"};
int Configurations::fps_choices[] = {-1, 60, 59, 55, 50, 45,
                                     40, 35, 30, 25, 20, 15};
int Configurations::color_scale_choices[] = {-1, 24, 16, 15, 8, 4, 2, 1};

uint8_t Configurations::system;
uint8_t Configurations::source;
std::string Configurations::server_ip;
std::string Configurations::client_ip;
std::string Configurations::my_own_used_ip;
uint16_t Configurations::port;
std::string Configurations::password;
bool Configurations::leave_client_config;
uint8_t Configurations::resolution;
uint8_t Configurations::fps;
uint8_t Configurations::color_scale;

uint8_t Configurations::video_chunk_seconds;
std::string Configurations::file_name = "";
std::string Configurations::camera_path;
cv::Rect2d Configurations::rect;
int Configurations::frame_width;
int Configurations::frame_height;
std::string Configurations::current_frame_path;
std::string Configurations::current_audio_path;


bool Configurations::intrusion_detection_enabled;
std::string Configurations::network;

Configurations::Configurations()
{
}

/**
 * Executes a command and returns the command return value.
 * @param   : cmd; command to execute.
 * @return  : std::string; command return message/value.
*/
std::string Configurations::execCmd(const char *cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    auto pipe = popen(cmd, "r");

    if (!pipe) throw std::runtime_error("popen() failed!");

    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != nullptr)
            result += buffer.data();
    }

    pclose(pipe);

    result.pop_back(); // remove \n character
    return result;
}
