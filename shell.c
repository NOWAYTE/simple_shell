#include "shell.h"

int main(__attribute__((unused))int argc, char **argv, char **envp)
{
	char *token = NULL;
	DIR *dp;
	char *path = NULL;
	char *path_copy = NULL;
	char *dir = NULL;
	char *cpy_cmd = NULL;
	char *cmd = NULL;
	size_t i = 0;
	int found = 0;
	int status;
	int c;
	int x = 0;
	pid_t id;
	char *delim = " \n";

	int argC = 0;
	char **argV = NULL;

	struct dirent *entry;

	_print("($) ", STDOUT_FILENO);

	while (getline(&cmd, &i, stdin) != -1)
		cpy_cmd = _strdup(cmd);

		token = strtok(cmd, delim);

		while (token)
		{

			token = strtok(NULL, delim);
			argC++;

		}

		argV = malloc(sizeof(char *) * argC);

		if (argV == NULL)
		{
			return (-1);

		}

		token = strtok(cpy_cmd, delim);

		while (token)
		{
			argV[x] = token;

			token = strtok(NULL, delim);
			x++;
		}

		argV[x] = NULL;

		path = _getenv("PATH");
		path_copy = _strdup(path);

		token = strtok(path_copy, ":");

		while (token)
		{
		
			char cmd[1024];

			sprintf(cmd, "%s/%s", token, argV[0]);

			if (access(cmd, X_OK) == 0)
			{
				found = 1;
				break;
			}

			free(path_copy);

			if (!found)
			{
				perror("No such file or directory ");
				continue;
			}

			id = fork();

			if (id == 0)
			{
				execve(argV[0], argV, envp);
				exit(EXIT_FAILURE);

			}
			else if(id < 0)
			{
				perror("Error");

			}
			else
			{
				do
				{
					waitpid(id, &status, WUNTRACED);
				}
			}
		}

		_print("($)", STDOUT_FILENO);
		argC = 0;
		x = 0;
		free(cpy_cmd);
	}
	while((c = _getchar()) == EOF)
	{
		break;
	}


	free(cmd);

	return (0);

}
