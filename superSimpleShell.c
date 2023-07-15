#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
/**
 * main - Implementation of a super simple shell
 *
 * Return: Always 0 (success)
 *
 */

int main(int argc, char *argv[])
{
	pid_t parent_pid;

	char *line = NULL;

	size_t i = 0;
	ssize_t read_n;

	printf("#cisfun$");

	line = strtok(argv, " ");

	while ((read_n = getline(&line, &i, stdin)) != -1)
	{

		char *envp[] = {NULL};

		if (argv[i] != NULL && strcmp(argv[1], "./ppid") == 0)
		{
			parent_pid = getpid();

			printf("%u \n", parent_pid);

		}

		if (execve(argv[1], argv, envp) == -1)
		{
			perror("Execve did not execute");

		}



		printf("#cisfun$");
	}

	return (0);
}


