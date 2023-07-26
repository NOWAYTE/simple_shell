#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *args[1024];
    int i;
    char *token;
    pid_t pid, wpid;
    int status;

    // Function to handle Ctrl+C (SIGINT) signal
    void sigint_handler(int sig) {
        printf("\nExiting due to Ctrl+C\n");
        exit(0);
    }

    // Trap the SIGINT
    signal(SIGINT, sigint_handler);

    while (1) {
        printf(":) ");
        getline(&line, &len, stdin);

        // Split the line into arguments
        i = 0;
        token = strtok(line, " \t\r\n\a");
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " \t\r\n\a");
        }
        args[i] = NULL;

        // Check if the command exists
        int found = 0;
        char *path = getenv("PATH");
        char *path_copy = strdup(path);
        token = strtok(path_copy, ":");
        while (token != NULL) {
            char cmd[1024];
            sprintf(cmd, "%s/%s", token, args[0]);
            if (access(cmd, X_OK) == 0) {
                found = 1;
                break;
            }
            token = strtok(NULL, ":");
        }
        free(path_copy);
        if (!found) {
            printf("%s: command not found\n", args[0]);
            continue;
        }

        // Fork a child process to execute the command
        pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("Error");
        } else {
            // Parent process
            do {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 0;
}

