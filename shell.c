#include "shell.h"

int main(__attribute__((unused))int argc, char **argv, char **envp)
{
	char *token = NULL;
	DIR *dp;
	char *path = NULL;
	char *dir = NULL;
	char *cpy_cmd = NULL;
	char *cmd = NULL;
	size_t i = 0;
	int c;
	int x = 0;
	pid_t id;
	char *delim = " \n";

	int argC = 0;
	char **argV = NULL;

	struct dirent *entry;

	_print("($) ", STDOUT_FILENO);

	while (getline(&cmd, &i, stdin) != -1)
	{
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
