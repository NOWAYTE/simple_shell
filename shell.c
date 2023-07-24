#include "shell.h"

int main()
{
	int argc = 0;
	int id;
	char **argv = NULL;
	char *delim = " \n";
	char **envp = NULL;

	char *token = NULL;
	char *cpy_cmd = NULL;


	char *cmd = NULL;
	size_t i = 0;
	int x = 0;


	_print("($) ", STDOUT_FILENO);

	while (getline(&cmd, &i, stdin) != -1)
	{
		cpy_cmd = strdup(cmd);

		token = strtok(cmd, delim);

		while (token)
		{

			token = strtok(NULL, delim);
			argc++;

		}

		argv = malloc(sizeof(char *) * argc);

		if (argv == NULL)
		{
			return (-1);

		}

		token = strtok(cpy_cmd, delim);

		while (token)
		{
			argv[x] = token;

			token = strtok(NULL, delim);
			x++;
		}

		argv[x] = NULL;

		id = fork();

		if (id != 0)
		{
			wait(0);

		}
		else
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				_print("No such file or directory \n", STDOUT_FILENO);

			}
			else
			{
				_print("No such file or directory.. something went wrong ", STDOUT_FILENO);

			}
		}

		_print("($)", STDOUT_FILENO);
		
		argc = 0;
		x = 0;

		free(cpy_cmd);

	}

	free(cmd);

	return (0);

}
