#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS_COUNT 10

void prompt() {
    printf("#cisfun$ ");
}

char* read_command() {
    char* command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    return command;
}

void execute_command(char* command) {
    char* arguments[MAX_ARGUMENTS_COUNT];
    int argument_count = 0;

    // split the command into arguments
    char* argument = strtok(command, " \t\n");
    while (argument != NULL) {
        arguments[argument_count++] = argument;
        argument = strtok(NULL, " \t\n");
    }
    arguments[argument_count] = NULL;

    pid_t pid = fork();

    if (pid < 0) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        if (execvp(arguments[0], arguments) < 0) {
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
        if (strlen(command) == 0) {
            // empty input
            continue;
        }

        execute_command(command);

        free(command);
    }

    return 0;
}
