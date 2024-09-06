#include "commend.hpp"
#include "server.hpp"

int main(){
  ServerController server;
  Command cmd;
std::string s;

  
  if(!server.socket_init()){
    std::cerr << "Failed to initialize socket.\n";
    return -1;
  }

  
  if(!server.server_listen()){
    std::cerr << "Can not listen on the server.\n";
    return -1;
  }

  while(true){
    std::cout << "Waiting for connection...\n";
    if(server.server_accept_client()){
      std::cout << "Client connected.\n";
      server.server_send("Enter command to execute or type 'exit' to close:\n");

      while(true){
        s = server.server_read();

        if (s.empty()) {
          std::cerr << "No data received from client.\n";
        } 
        else 
        {
          std::cout << "Data received: " << s << std::endl;

          if(s == "exit"){
            server.server_send("Exiting...\n");
            server.close_server();
            server.server_send("Server closed.\n");
            return 0;
          } 
          else if(s == "terminal"){
            cmd.openTerminal();
            server.server_send("Opening terminal.\n");
          } 
          else if(s == "firefox"){
            cmd.openFirefox();
            server.server_send("Opening Firefox.\n");
          }
           else {
            server.server_send("Unknown command.\n");
          }
        }
        }
      }
    }
  }

