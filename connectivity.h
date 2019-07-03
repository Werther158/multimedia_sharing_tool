#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#include <stdlib.h>
#include <string>
#include <curl/curl.h>

class Connectivity
{
public:
    Connectivity();
    ~Connectivity();
    static std::string getPublicIp();
};

#endif // CONNECTIVITY_H
