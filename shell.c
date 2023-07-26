#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void prompt() {
    printf("#cisfun$ ");
}

char* read_command() {
    char* command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    return command;
}

void execute_command(char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        char* args[2] = {command, NULL};
        if (execvp(args[0], args) < 0) {
            printf("Error: command not found\n");
            exit(1);
        }
    } else {
        // parent process
        wait(NULL);
    }
}

int main() {
    while (1) {
        prompt();

        char* command = read_command();
        if (strlen(command) <= 1) {
            // empty input
            continue;
        }

        // remove newline character
        command[strlen(command) - 1] = '\0';

        execute_command(command);

        free(command);
    }

    return 0;
}
