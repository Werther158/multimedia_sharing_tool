#include <connectivity.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <sstream>
#include <iostream>

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data;
    return size * nmemb;
}

Connectivity::Connectivity() {
}

Connectivity::~Connectivity() {
}

string Connectivity::getPublicIp() {
    void* curl;
    string output;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org/");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
    /* Perform the request, res will get the return code */
    CURLcode res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s. Check your internet connection.\n",
                curl_easy_strerror(res));
        output = "127.0.0.1";
    }
    else {
        output = out.str();
    }
    curl_easy_cleanup(curl);

    return output;
}

int Connectivity::tcpServer(uint16_t PORT)
{
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    emit writeText("Server running");
    if ((sock = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read(sock, buffer, BUFFER_SIZE);
    send(sock, hello, strlen(hello), 0);

    emit writeText("Client connected\n");
    emit clientConnected();

    tcpRead();

    return 0;
}

int Connectivity::tcpClient(string server_ip, uint16_t PORT)
{
    char *hello = "Hello from client";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, server_ip.c_str(), &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (::connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0 );
    valread = read(sock, buffer, BUFFER_SIZE);

    emit writeText("Client connected\n");
    emit clientConnected();

    tcpRead();

    return 0;
}

void Connectivity::tcpRead()
{
    while(1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        valread = read(sock, buffer, BUFFER_SIZE);

        if(buffer[0] == -1) // The other guy clicked disconnect
        {
            emit otherGuyDisconnected();
            break;
        }
        if(buffer[0] == -2) // (Server side) Start sending video stream to client
        {
            emit startServerStream();
        }
        else
        if(buffer[0] == -3) // (Client side) Stop receiving video stream
        {
            emit stopReceivingVideoStream();
        }
        else
        if(Configurations::system == SERVER)
            emit writeText("CLIENT: " + QString(buffer));
        else
            emit writeText("SERVER: " + QString(buffer));
    }
}

void Connectivity::tcpWriteData(QString text)
{
    send(sock, text.toStdString().c_str(), strlen(text.toStdString().c_str()), 0);
    if(Configurations::system == CLIENT)
        emit writeText("CLIENT: " + text);
    else
        emit writeText("SERVER: " + text);
}

void Connectivity::tcpWriteCommand(char command)
{
    buffer[0] = command;
    send(sock, buffer, 1, 0);
}
