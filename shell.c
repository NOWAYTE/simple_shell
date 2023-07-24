#include "shell.h"

int main()
{
	int argc = 0;
	char **argv = NULL;
	char *delim = " \n";

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

		printf("%d \n", argc);

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

		for (x = 0; x < argc; x++)
		{
			printf("%s \n", argv[x]);

		}

		_print("($)", STDOUT_FILENO);
		
		argc = 0;
		x = 0;

	}

	free(cmd);
	free(cpy_cmd);

	return (0);

}
