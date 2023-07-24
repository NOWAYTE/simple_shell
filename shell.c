#include "shell.h"

int main(__attribute__((unused))int argc, char **argv, __attribute__((unused))char **envp)
{
	char *token = NULL;
	char *cpy_cmd = NULL;
	char *cmd = NULL;
	size_t i = 0;
	int x = 1;
	int id = 0;
	char *delim = " \n";

	int argC = 0;
	char **argV = NULL;
	char **envP = NULL;

	_print("($) ", STDOUT_FILENO);

	while (getline(&cmd, &i, stdin) != -1)
	{
		cpy_cmd = strdup(cmd);

		token = strtok(cmd, delim);

		while (token)
		{

			token = strtok(NULL, delim);
			argC++;

		}

		argV = malloc(sizeof(char *) * argC);
		*argV = argv[0];

		if (argv == NULL)
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

		id = fork();

		if (id != 0)
		{
			wait(0);

		}
		else
		{
			if (execve(argV[1], argV, envP) == -1)
			{
				_print(argv[0], STDOUT_FILENO);
				_print(": ", STDOUT_FILENO);
				_print("No such file or directory \n", STDOUT_FILENO);

			}
			else
			{
				_print("No such file or directory.. something went wrong ", STDOUT_FILENO);

			}
		}

		_print("($)", STDOUT_FILENO);
		
		argC = 0;
		x = 1;

		free(cpy_cmd);

	}

	free(cmd);

	return (0);

}
