#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#define BUFFER_SIZE 1024

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

#include <configurations.h>

class Connectivity : public QObject
{
    Q_OBJECT
private:
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    void tcpRead();
public:
    Connectivity();
    ~Connectivity();
    static std::string getPublicIp();
    int tcpServer(uint16_t PORT);
    int tcpClient(std::string server_ip, uint16_t PORT);
    void tcpWriteData(QString text);
    void tcpWriteCommand(char command);
signals:
    void writeText(QString text);
    void clientConnected();
    void otherGuyDisconnected();
};

#endif // CONNECTIVITY_H
