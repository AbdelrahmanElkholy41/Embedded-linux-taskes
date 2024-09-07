#include <iostream>
#include <cstdlib> // for system()
#include "commend.hpp" // or the correct path to command.hpp


void Command::openTerminal() {
    std::cout << "Attempting to open terminal.\n"; // رسالة تصحيحية
    int result = system("gnome-terminal");
    if (result != 0) {
        std::cerr << "Failed to open terminal.\n";
    } else {
        std::cout << "Terminal opened successfully.\n"; // رسالة تصحيحية
    }
}


void Command::openFirefox(){
    int result = system("firefox");
    if (result != 0) {
        std::cerr << "Failed to open Firefox." << std::endl;
    }
}

void Command::openFacebook(){
    int result = system("xdg-open https://www.facebook.com");
    if (result != 0) {
        std::cerr << "Failed to open Facebook." << std::endl;
    }
}

void Command::openGitHub(){
    int result = system("xdg-open https://www.github.com");
    if (result != 0) {
        std::cerr << "Failed to open GitHub." << std::endl;
    }
}

void Command::openLinkedIn(){
    int result = system("xdg-open https://www.linkedin.com");
    if (result != 0) {
        std::cerr << "Failed to open LinkedIn." << std::endl;
    }
}

void Command::openYouTube(){
    int result = system("xdg-open https://www.youtube.com");
    if (result != 0) {
        std::cerr << "Failed to open YouTube." << std::endl;
    }
}

void Command::shutdown() {
    int result = system("shutdown now");
    if (result != 0) {
        std::cerr << "Failed to shutdown the system." << std::endl;
    }
}

void Command::restart() {
    int result = system("reboot");
    if (result != 0) {
        std::cerr << "Failed to restart the system." << std::endl;
    }
}
void Command::openSettings() {
    system("gnome-control-center &");
}

