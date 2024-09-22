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
       
        // Fork a child process
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // This is the child process
             char *arg[MAX_INPUT_LENGTH]={input,NULL};
            execvp(input, arg);  // Execute the command with arguments
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
