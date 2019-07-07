#include "configurations.h"

using namespace std;

std::string Configurations::source_choices[] = {"Video file", "Camera", "Screen"};
std::string Configurations::resolution_choices[] = {"3840 x 2160", "2560 x 1440", "1920 x 1080",
                                   "1600 x 900", "1280 x 720", "854 x 480", "640 x 360",
                                   "426 x 240", "256 x 144"};
int Configurations::buffer_choices[] = {128, 64, 32, 16, 8, 0};
int Configurations::color_scale_choices[] = {24, 16, 15, 8, 4, 2, 1};
std::string Configurations::controls_choices[] = {"T + M", "C", "T + M + C"};

std::string Configurations::file_name;

uint8_t Configurations::system;
uint8_t Configurations::source;
std::string Configurations::server_ip;
std::string Configurations::client_ip;
uint16_t Configurations::port;
std::string Configurations::password;
bool Configurations::leave_client_config;
uint8_t Configurations::resolution;
int Configurations::fps;
int Configurations::buffer;
int Configurations::color_scale;
uint8_t Configurations::controls;

Configurations::Configurations()
{

}
