#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	char *line = NULL;
	char **argv = NULL;
	int argc = 1;
	int x = 0;

	char *token = NULL;
	char *tok = NULL;
	char *delim = " ";

	ssize_t read_n;
	size_t i = 0;

	printf("#cisfun$ ");

	while ((read_n = getline(&line, &i, stdin)) != -1)
	{
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

		tok =  strtok(line, delim);

		while(token)
		{
			argv[x] = tok;;

			tok = strtok(NULL, delim);
			printf("%s \n", argv[x]);
			x++;
		}
		argv[x] = NULL;

		printf("%d", argc);

		argc = 0;
		x = 0;

		printf("#cisfun$ ");
		

	}


	free(line);

	return (0);

}
