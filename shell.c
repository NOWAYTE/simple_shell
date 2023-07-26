#include "shell.h"

int main(__attribute__((unused))int argc, char **argv, char **envp)
{
    char *token = NULL;
    char *cpy_cmd = NULL;
    char *cmd = NULL;
    size_t i = 0;
    int c;
    int x = 0;
    pid_t id;
    char *delim = " \n";

    int argC = 0;
    char **argV = NULL;

    while (1)
    {
        _print("($) ", STDOUT_FILENO);
        if (getline(&cmd, &i, stdin) == -1)
            break;

        cpy_cmd = _strdup(cmd);

        token = strtok(cmd, delim);

        while (token)
        {
            token = strtok(NULL, delim);
            argC++;
        }

        argV = malloc(sizeof(char *) * (argC + 1));

        if (argV == NULL)
        {
            return (-1);
        }

        argV[x] = strtok(cpy_cmd, delim);

        while (argV[x] != NULL)
        {
            x++;
            argV[x] = strtok(NULL, delim);
        }

        argV[x] = NULL;

        if (_strcmp(argV[0], "ls") == 0)
        {
            // Use execvp to search for the command in the PATH
            execvp(argV[0], argV);

            // If execvp returns, the command was not found
            _print(argv[0], STDOUT_FILENO);
            _print(": ", STDOUT_FILENO);
            _print("command not found\n", STDOUT_FILENO);

            // Free memory and start over
            free(cpy_cmd);
            free(argV);
            argC = 0;
            x = 0;
            continue;
        }

        id = fork();

        if (id != 0)
        {
            wait(NULL);
        }
        else
        {
            execve(argV[0], argV, envp);
            _print(argv[0], STDOUT_FILENO);
            _print(": ", STDOUT_FILENO);
            _print("command not found\n", STDOUT_FILENO);
            exit(EXIT_FAILURE);
        }

        free(cpy_cmd);
        free(argV);
        argC = 0;
        x = 0;
    }

    free(cmd);

    return (0);
}
