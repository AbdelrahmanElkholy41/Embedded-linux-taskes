#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <array>
#include <algorithm>  // For std::find_if
#include <cctype>     // For std::isspace

class ServerController {
    private:
        int socket_id;
        int client_id;
        std::array<char, 50000> buffer;

    public:
        ServerController();
        ~ServerController();
        bool socket_init();
        bool server_listen();
        bool server_accept_client();
        bool server_send(const std::string &message);
        std::string server_read();
        void close_listeing();
        void close_listeing_client();
        void close_server();
        void trim_end(std::string& str);
    



};

#endif
