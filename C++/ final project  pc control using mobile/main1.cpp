#include "commend.hpp"
#include "server.hpp"
#include <iostream>
#include <string>

int main() {
    ServerController server;
    Command cmd;
    std::string s;

    if (!server.socket_init()) {
        std::cerr << "Failed to initialize socket.\n";
        return -1;
    }

    if (!server.server_listen()) {
        std::cerr << "Cannot listen on the server.\n";
        return -1;
    }

    while (true) {
        std::cout << "Waiting for connection...\n";
        if (server.server_accept_client()) {
            std::cout << "Client connected.\n";
            server.server_send("Enter command to execute or type 'exit' to close:\n");

            while (true) {
                s = server.server_read();

                if (s.empty()) {
                    std::cerr << "No data received from client.\n";
                } else {
                    server.trim_end(s);  // Trim trailing whitespace here
                    std::cout << "Data received: " << s << std::endl;

                    if (s == "exit") {
                        server.server_send("Exiting...\n");
                        server.close_server();
                        server.server_send("Server closed.\n");
                        return 0;
                    } 
                    
                    else if (s == "terminal") {
                        cmd.openTerminal();
                        server.server_send("Opening terminal.\n");
                    } 
                    
                    else if (s == "firefox") {
                        cmd.openFirefox();
                        server.server_send("Opening Firefox.\n");
                    }
                    
                    else if(s == "facebook"){
                      cmd.openFacebook();
                      server.server_send("Opening Facebook.\n");
                    } 
                    
                    else if(s == "github"){
                      cmd.openGitHub();
                      server.server_send("Opening GitHub.\n");
                    }
                    
                     else if(s == "LinkedIn"){
                      cmd.openLinkedIn();
                      server.server_send("Opening LinkedIn.\n");
                    } 
                    
                    else if(s == "youtube"){
                      cmd.openYouTube();
                      server.server_send("Opening YouTube.\n");
                    } 
                    
                    else if(s == "shutdown"){
                      cmd.shutdown();
                      server.server_send("Shutting down the system.\n");
                    } 
                    
                    else if(s == "restart"){
                      cmd.restart();
                      server.server_send("Restarting the system.\n"); 
                              
                    }

                    else if(s=="settings"){
                      cmd.openSettings();
                      server.server_send("Opening Settings.\n");
                    }
                    
                    else {
                                  server.server_send("Unknown command.\n");
                              }   
                }
            }
        }
    }
}
