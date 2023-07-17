#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(void)
{

	char *cmd = NULL;
	size_t i = 0;
	ssize_t read_n;
	int argc = 0;
	char **argv = NULL;
	int n = 0;
	int x = 0;
	char *delim = " ";
	char *token = NULL;


	printf("#cisfun$ ");

	while ((read_n = getline(&cmd, &i, stdin)) != -1)
	{
		token = strtok(cmd, delim);

		while (token != NULL)
		{
			argc++;

			token = strtok(NULL, delim);

		}

		argv = malloc(sizeof(char *) * argc);

		token = strtok(cmd, delim);

		while (token != NULL)
		{
			argv[n] = token;
			n++;

			token = strtok(NULL, delim);

		}

		for (x = 0; x < argc; x++)
		{
			printf("%s", argv[x]);
		}

		printf("#cisfun$ ");

		free(argv);

		argc = 0;
		n = 0;

	}

	free(cmd);

	return (0);

}

