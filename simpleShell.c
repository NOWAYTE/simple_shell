#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	char *line = NULL;
	int id;
	char **argv = NULL;
	int argc = 0;
	char *cmd = NULL;
	int x = 0;
	char *envp[] = {NULL};

	char *token = NULL;
	char *tok = NULL;
	char *delim = " ";

	ssize_t read_n;
	size_t i = 0;

	printf("#cisfun$ ");

	while ((read_n = getline(&line, &i, stdin)) != -1)
	{
		cmd = strdup(line);

		token = strtok(line, delim);

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

		tok =  strtok(cmd, delim);

		while(tok)
		{
			argv[x] = tok;;

			tok = strtok(NULL, delim);
			printf("%s \n", argv[x]);
			x++;
		}
		argv[x] = NULL;

		id = fork();

		if (id != 0)
		{
			wait();

		}
		else
		{
			printf("======================================== \n");

			if (execve(argv[0], argv, envp) == -1)
			{
				perror("Execve did not execute");

			}
			else
			{
				printf("Something went wrong ");

			}
		}


		printf("%d \n", argc);

		argc = 0;
		x = 0;

		printf("#cisfun$ ");
		

	}


	free(line);

	return (0);

}
