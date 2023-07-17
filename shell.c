#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{

	char *cmd = NULL;
	size_t i = 0;
	int n = 0;
	int argc = 0;
	char **argv = NULL;
	char *token = NULL;
	char *delim = " ";
	char *cpy = NULL;

	printf("#cisfun$ ");

	while (getline(&cmd, &i, stdin) != -1)
	{
		cmd[strcspn(cmd, "\n")] = 0;
		token = strtok(cmd, delim);

		while (token !=  NULL)
		{
			argc++;

			token = strtok(NULL, delim);

		}

		printf("%d\n", argc);

		argv = malloc(sizeof(char *) * (argc + 1));

		if (argv == NULL)
		{
			return (-1);

		}

		cpy = strdup(cmd);

		token = strtok(cpy, delim);
		
		while (token)
		{
			argv[n] = token;

			token = strtok(NULL, delim);
			n++;
		}

		printf("%s \n", argv[0]);
		printf("%s \n", argv[1]);

		printf("#cisfun$ ");

		n = 0;
		argc = 0;
		
		free(argv);
		free(cpy);

	}

	free(cmd);

	return (0);
}






