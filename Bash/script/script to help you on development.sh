#!/bin/bash

# Function to display the menu
function show_menu {
    echo "===================================="
    echo "Welcome to the Dev Wiki!"
    echo "===================================="
    echo "1. C++ Hello World"
    echo "2. Python Hello World"
    echo "3. Linux Commands"
    echo "4. Bash Hello World"
    echo "5. Exit"
    echo "===================================="
}

# Function to display a C++ Hello World example
function cpp_hello_world {
    echo "C++ Hello World Example:"
    echo "------------------------------------"
    cat <<EOL
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
EOL
    echo "------------------------------------"
}

# Function to display a Python Hello World example
function python_hello_world {
    echo "Python Hello World Example:"
    echo "------------------------------------"
    cat <<EOL
print("Hello, World!")
EOL
    echo "------------------------------------"
}

# Function to display useful Linux commands
function linux_commands {
    echo "Common Linux Commands:"
    echo "------------------------------------"
    echo "1. List files in a directory: ls"
    echo "2. Show current directory: pwd"
    echo "3. Display disk usage: df -h"
    echo "4. Display free memory: free -h"
    echo "5. Find a file by name: find /path/to/search -name 'filename'"
    echo "------------------------------------"
}

# Function to display a Bash Hello World example
function bash_hello_world {
    echo "Bash Hello World Example:"
    echo "------------------------------------"
    cat <<EOL
#!/bin/bash
echo "Hello, World!"
EOL
    echo "------------------------------------"
}

# Main loop to show the menu and process user input
while true; do
    show_menu
    read -p "Choose an option [1-5]: " choice

    case $choice in
        1)
            cpp_hello_world
            ;;
        2)
            python_hello_world
            ;;
        3)
            linux_commands
            ;;
        4)
            bash_hello_world
            ;;
        5)
            echo "Exiting Dev Wiki. Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice, please try again."
            ;;
    esac

    echo
done
