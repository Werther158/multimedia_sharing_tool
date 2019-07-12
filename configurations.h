#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <stdlib.h>
#include <string>

#define SERVER 0
#define CLIENT 1

class Configurations
{
public:
    Configurations();

    static std::string source_choices[];
    static std::string resolution_choices[];
    static int fps_choices[];
    static int buffer_choices[];
    static int color_scale_choices[];
    static std::string controls_choices[];

    static std::string file_name;

    static uint8_t system;
    static uint8_t source;
    static std::string server_ip;
    static std::string client_ip;
    static std::string my_own_used_ip; // My Ip used to connect to Server or Client
    static uint16_t port;
    static std::string password;
    static bool leave_client_config;
    static uint8_t resolution;
    static uint8_t fps;
    static uint8_t buffer;
    static uint8_t color_scale;
    static uint8_t controls;
};

#endif // CONFIGURATIONS_H
