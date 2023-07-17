#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(void)
{

	char *cmd = NULL;
	int argc = 0;
	int n = 0;
	int x = 0;
	char **argv = NULL;

	size_t i = 0;

	char *token = NULL;

	ssize_t read_n;

	char *delim = " ";

	printf("#cisfun$ ");

	while ((read_n = getline(&cmd, &i, stdin)) == -1)
	{
		return (-1);
	}

	token = strtok(cmd, delim);

	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}

	argv = malloc(sizeof(char *) *argc);

	while (token)
	{
		argv[n] = token;

		token = strtok(NULL, delim);
		n++;
	}

	while (argv)
	{
		printf("%s", argv[x]);
		x++;
	}

	return (0);

}
