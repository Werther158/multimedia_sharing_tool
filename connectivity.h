#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#include <stdlib.h>
#include <string>
#include <curl/curl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

class Connectivity
{
public:
    Connectivity();
    ~Connectivity();
    static std::string getPublicIp();
    static int tcpServer(uint16_t PORT);
    static int tcpClient(std::string server_ip, uint16_t PORT);
};

#endif // CONNECTIVITY_H
