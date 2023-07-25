#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void parse_input(char *input, char **args) {
    char *token;
    int i = 0;

    token = strtok(input, " \t\n");
    while (token) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

char *find_command_in_path(const char *command, char *path) {
    char *token;
    char *full_path = NULL;
    char buffer[MAX_INPUT_SIZE];

    strcpy(buffer, path);
    token = strtok(buffer, ":");

    while (token) {
        sprintf(buffer, "%s/%s", token, command);
        if (access(buffer, X_OK) == 0) {
            full_path = strdup(buffer);
            break;
        }
        token = strtok(NULL, ":");
    }

    return full_path;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **envp) {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_INPUT_SIZE];
    pid_t pid;
    int status;

    char *path = _getenv("PATH");

    while (1) {
        printf("($) ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }
        parse_input(input, args);
        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char *full_path = find_command_in_path(args[0], path);

            if (full_path != NULL) {
                if (execve(full_path, args, envp) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
                free(full_path);
            } else {
                printf("Command not found: %s\n", args[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&status);
        }
    }

    return 0;
}

