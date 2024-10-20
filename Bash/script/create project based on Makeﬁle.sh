#!/bin/bash

# Check if the project name is provided
# if [ -z "$1" ]; then
#     echo "Usage: $0 <project_name>"
#     exit 1
# fi

# Project name from command line
PROJECT_NAME=$1

# Create project directories
mkdir -p $PROJECT_NAME/{src,include,bin}

# Create a basic main.cpp file in src
cat <<EOL > $PROJECT_NAME/src/main.cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
EOL

# Create a basic Makefile in the project root
cat <<EOL > $PROJECT_NAME/Makefile
# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Wall -g

# Directories
SRCDIR = src
INCDIR = include
BINDIR = bin

# Target executable name
TARGET = \$(BINDIR)/$PROJECT_NAME

# Source files
SOURCES = \$(wildcard \$(SRCDIR)/*.cpp)

# Object files
OBJECTS = \$(SOURCES:.cpp=.o)

# Build the project
all: \$(TARGET)

\$(TARGET): \$(OBJECTS)
	\$(CXX) \$(CXXFLAGS) -o \$(TARGET) \$(OBJECTS)

# Compile source files into object files
\$(SRCDIR)/%.o: \$(SRCDIR)/%.cpp
	\$(CXX) \$(CXXFLAGS) -c \$< -o \$@

# Clean build files
clean:
	rm -f \$(SRCDIR)/*.o \$(TARGET)

# Run the project
run: all
	./\$(TARGET)

.PHONY: all clean run
EOL

echo "Project '$PROJECT_NAME' created successfully!"
