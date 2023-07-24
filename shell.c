#include "shell.h"

int main()
{
	int argc = 0;
	char **argv = NULL;
	char *delim = " ";

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
			argc++;

			token = strtok(NULL, delim);

		}

		printf("%d", argc);

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

		while (argv)
		{
			printf("%s", argv[x++]);

		}

	}

	free(cmd);
	free(cpy_cmd);

	return (0);

}
