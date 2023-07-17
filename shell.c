#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{

	char *cmd = NULL;
	size_t i = 0;
	int n = 0;
	int x = 0;
	int argc = 0;
	char **argv = NULL;
	char *token = NULL;
	char *delim = " ";
	char *cpy = NULL;

	printf("#cisfun$ ");

	while (getline(&cmd, &i, stdin) != -1)
	{
		token = strtok(cmd, delim);

		while (token !=  NULL)
		{
			argc++;

			token = strtok(NULL, delim);

		}

		argv = malloc(sizeof(char *) * argc);

		cpy = strdup(cmd);

		token = strtok(cpy, delim);

		while (token != NULL)
		{
			argv[n] = token;

			token = strtok(NULL, delim);

			n++;
		}

		for (x = 0; x < argc; x ++)
		{
			printf("%s\n", argv[x]);

		}

		printf("#cisfun$ ");

		n = 0;
		argc = 0;
		
		free(argv);
		free(cpy);

	}

	free(cmd);

	return (0);
}






