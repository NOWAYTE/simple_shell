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
	char *token = NULL;
	char *delim = NULL;


	printf("#cisfun$ ");

	while ((read_n = getline(&cmd, &i, stdin)) != -1)
	{
		token = strtok(cmd, delim);

		while (token)
		{
			argc++;

			token = strtok(NULL, delim);

		}

		argv = malloc(sizeof(char *) * argc);

		token = strtok(cmd, delim);

		while (token)
		{
			argv[n] = token;
			n++;

			token = strtok(NULL, delim);

		}

		free(argv);

		printf("#cisfun$ ");

	}

	free(cmd);

	return (0);

}

