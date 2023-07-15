#include<stdio.h>
#include<stdlib.h>
/**
 * main - Function that reads a command from the
 * user and prints it to next line
 *
 * Return: Always 0 (success)
 *
 */

int main()
{
	char *line = NULL;

	size_t i = 0;
	ssize_t read_n;

	printf("$ ");

	while ((read_n = getline(&line, &i, stdin)) != -1)
	{

		printf("%s", line);
		printf("$ ");

	}

	free(line);

	return (0);

}
