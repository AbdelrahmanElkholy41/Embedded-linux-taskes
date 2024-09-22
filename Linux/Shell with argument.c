#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 256  // Define the input length
#define MAX_ARGS 10  // Define the maximum number of arguments

int main() {
    char input[MAX_INPUT_LENGTH];
    char *argv[MAX_ARGS];  // Array to store arguments
    while (1) {
        printf("SimpleShell$ ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (input[0] == '\n') {
            continue;
        }
        // Remove the \n character from input
        input[strcspn(input, "\n")] = '\0';

        // Exit
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            printf("Exiting the shell...\n");
            break;
        }

        // Parse the input into arguments
        int argc = 0;
        char *token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;  // Null-terminate the argument array

        // Fork a child process
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // This is the child process
            execvp(argv[0], argv);  // Execute the command with arguments
            perror("Execution failed");
            exit(EXIT_FAILURE);
        } else {
            // This is the parent process
            int status;
            waitpid(child_pid, &status, 0);
        }
    }
    return 0;
}
