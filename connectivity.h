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
#include <QObject>

class Connectivity : public QObject
{
    Q_OBJECT
public:
    Connectivity();
    ~Connectivity();
    static std::string getPublicIp();
    int tcpServer(uint16_t PORT);
    int tcpClient(std::string server_ip, uint16_t PORT);
signals:
    void writeText(QString text);
};

#endif // CONNECTIVITY_H
