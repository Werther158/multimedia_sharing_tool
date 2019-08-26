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
#include <curl/easy.h>
#include <sstream>
#include <iostream>
#include <time.h>

#include <configurations.h>

class Connectivity : public QObject
{
    Q_OBJECT
private:
    int sock; // Used in Tcp socket
    ssize_t valread;
    struct sockaddr_in serv_addr;
    int server_fd;
    struct sockaddr_in address;
    int opt;
    int addrlen;
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
    void killTcpSocket();
signals:
    void writeText(QString text);
    void clientConnected();
    void otherGuyDisconnected();
    void startServerStream();
    void stopReceivingVideoStream(bool);
    void streamingEnded();
    void startStreaming();
};

#endif // CONNECTIVITY_H
