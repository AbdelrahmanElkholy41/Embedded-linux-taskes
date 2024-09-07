#include "server.hpp"

ServerController::ServerController() {
    // Constructor code (if needed)
}

ServerController::~ServerController() {
    // Destructor code to clean up resources, if any
}

bool ServerController::socket_init() {
    socket_id = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_id == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return false;
    }

    sockaddr_in sok;
    sok.sin_family = AF_INET;
    sok.sin_port = htons(8080);
    sok.sin_addr.s_addr = INADDR_ANY;

    int b = bind(socket_id, (sockaddr *)&sok, sizeof(sok));
    if (b == -1) {
        std::cerr << "Can not bind." << std::endl;
        return false;
    }

    return true;
}

bool ServerController::server_listen() {
    int b=listen(socket_id, 5);
    if ( b < -1) {
        std::cerr << "Can not listen." << std::endl;
        return false;
    }
    return true;
}

bool ServerController::server_accept_client() {
    sockaddr_in client0;
    socklen_t client_len = sizeof(client0);
    client_id = accept(socket_id, (sockaddr *)&client0, &client_len);
    if (client_id < 0) {
        std::cerr << "Failed to accept client." << std::endl;
        return false;
    }
    return true;
}

bool ServerController::server_send(const std::string &message) {
    send(client_id, message.data(), message.size(), 0);
    return true;
}

void ServerController::trim_end(std::string& str) {
    str.erase(
        std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), str.end());
}


std::string ServerController::server_read() {
    ssize_t bytes_read = recv(client_id,static_cast<void*>(buffer.data()), buffer.size(), 0);
    
    if (bytes_read < 0) {
        std::cerr << "Error in recv." << std::endl;
        return "Error";
    } else if (bytes_read == 0) {
        std::cerr << "Client closed the connection." << std::endl;
        return "";  // Return an empty string to indicate the connection was closed
    } else {
        return std::string(buffer.data(), bytes_read);
    }
}
void ServerController::close_server(){
   
    if(client_id!=-1){
        close(client_id);
         client_id=-1;
    }
}

void ServerController::close_listeing_client(){
    close(client_id);
}

void ServerController::close_listeing(){
    close(socket_id);
}

