//_____________________________________________________________________________
//_____________________________________________________________________________
//                                CONNECTIVITY
// Manages the TCP/IP Client-Server connection and communication, allowing the
// exchange of messages and commands between the client and the server.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "connectivity.h"

/**
 * Used by curl to write a payload on his stream; this allows to
 * obtain the current public ip address.
*/
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    std::string data(reinterpret_cast<const char*>(ptr),
                     reinterpret_cast<size_t>(size) * nmemb);
    *(reinterpret_cast<std::stringstream*>(stream)) << data;
    return size * nmemb;
}

Connectivity::Connectivity()
{
    sock = 0;
    opt = 1;
    addrlen = sizeof(address);
}

Connectivity::~Connectivity()
{
}

/**
 * Retrieve the current public ip address.
 * @param   : void.
 * @return  : std::string; public ip address.
*/
std::string Connectivity::getPublicIp()
{
    void* curl;
    std::string output;
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
        fprintf(stderr, "curl_easy_perform() failed: "
                        "%s. Check your internet connection.\n",
                curl_easy_strerror(res));
        output = "127.0.0.1";
    }
    else {
        output = out.str();
    }
    curl_easy_cleanup(curl);

    return output;
}

/**
 * Start TCP Server.
 * @param   : PORT; choosen port.
 * @return  : int; return value success / error.
*/
int Connectivity::tcpServer(uint16_t PORT)
{
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
    if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&address),
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

    do {
        if ((sock = accept(server_fd, reinterpret_cast
                           <struct sockaddr *>(&address),
                           reinterpret_cast<socklen_t*>(&addrlen)))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(sock, buffer, BUFFER_SIZE);
        if (std::string(buffer) == Configurations::password)
        {
            send(sock, "ok", strlen(Configurations::client_ip.c_str()), 0);
        }
        else
        {
            send(sock, "no", strlen(Configurations::client_ip.c_str()), 0);
        }
    } while(std::string(buffer) != Configurations::password);

    valread = read(sock, buffer, BUFFER_SIZE);
    send(sock, Configurations::client_ip.c_str(),
         strlen(Configurations::client_ip.c_str()), 0);
    Configurations::my_own_used_ip = buffer;

    emit writeText("Client connected");
    emit clientConnected();

    tcpRead();

    return 0;
}

/**
 * Start TCP Client.
 * @param   : server_ip; server's ip.
 * @param   : PORT; choosen port.
 * @return  : int; return value success / error.
*/
int Connectivity::tcpClient(std::string server_ip, uint16_t PORT)
{
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

    if (::connect(sock, reinterpret_cast<struct sockaddr *>(&serv_addr),
                  sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, Configurations::password.c_str(),
         strlen(Configurations::server_ip.c_str()), 0 );
    valread = read(sock, buffer, BUFFER_SIZE);

    if(std::string(buffer) == "ok")
    {
        send(sock, Configurations::server_ip.c_str(),
             strlen(Configurations::server_ip.c_str()), 0 );
        valread = read(sock, buffer, BUFFER_SIZE);
        Configurations::my_own_used_ip = buffer;

        // Fill buffer with client configurations
        buffer[1] = static_cast<char>(Configurations::resolution);
        buffer[2] = static_cast<char>(Configurations::fps);
        buffer[3] = static_cast<char>(Configurations::color_scale);
        buffer[4] = static_cast<char>(Configurations::video_chunk_seconds);
        if(Configurations::intrusion_detection_enabled)
            buffer[5] = 1;
        else
            buffer[5] = 0;

        // Transfer client's configurations to the server
        tcpWriteCommand(-6);

        emit writeText("Client connected");
        emit clientConnected();

        tcpRead();
    }
    else
        emit otherGuyDisconnected();

    return 0;
}

/**
 * Used by client to continuesly listen for new messages from the server.
 * @param   : void.
 * @return  : void.
*/
void Connectivity::tcpRead()
{
    while(1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        valread = read(sock, buffer, BUFFER_SIZE);

        // The other guy clicked disconnect
        if(buffer[0] == (char)-1)
        {
            emit otherGuyDisconnected();
            break;
        }
        // (Server side) Start sending video stream to client
        if(buffer[0] == (char)-2)
        {
            emit startServerStream();
        }
        else
        // (Client side) Stop receiving video stream
        if(buffer[0] == (char)-3)
        {
            emit stopReceivingVideoStream(false);
        }
        else
        // (Server side) Streaming ended
        if(buffer[0] == (char)-4)
        {
            emit streamingEnded();
        }
        else
        // (Client side) Start streaming
        if(buffer[0] == (char)-5)
        {
            emit startStreaming();
        }
        else
        // (Server side) Receive client configuration
        if(buffer[0] == (char)-6)
        {
            if(Configurations::leave_client_config)
            {
                Configurations::resolution = static_cast<uint8_t>(buffer[1]);
                Configurations::fps = static_cast<uint8_t>(buffer[2]);
                Configurations::color_scale = static_cast<uint8_t>(buffer[3]);
                Configurations::video_chunk_seconds = static_cast<uint8_t>(buffer[4]);
                if(buffer[5] == 1)
                    Configurations::intrusion_detection_enabled = true;
                else
                    Configurations::intrusion_detection_enabled = false;
            }
        }
        else
        if(Configurations::system == SERVER)
            emit writeText("CLIENT: " + QString(buffer));
        else
            emit writeText("SERVER: " + QString(buffer));
    }
}

/**
 * Send text to socket and emit a signal to write text to the
 * local machine frame textBox.
 * @param   : text; text to send.
 * @return  : void.
*/
void Connectivity::tcpWriteData(QString text)
{
    send(sock, text.toStdString().c_str(),
         strlen(text.toStdString().c_str()), 0);
    if(Configurations::system == CLIENT)
        emit writeText("CLIENT: " + text);
    else
        emit writeText("SERVER: " + text);
}

/**
 * Send a command through the socket.
 * @param   : command; command to send.
 * @return  : void.
*/
void Connectivity::tcpWriteCommand(char command)
{
    buffer[0] = command;
    send(sock, buffer, 1, 0);
}

/**
 * Close the socket.
 * @param   : void.
 * @return  : void.
*/
void Connectivity::killTcpSocket()
{
    close(sock);
}
