#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_path()
{
	char *path;
	char *token;

	path = getenv("PATH");

	token = strtok(path, " : ");

	while (token)
	{
		printf("%s \n", token);

		token = strtok(NULL, " : ");

	}

}
