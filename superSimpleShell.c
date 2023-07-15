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

	while ((read_n = getline(&line, &i, stdin)) != -1)
	{


		char *argv[] = {argv[0], argv[1], NULL};

		char *envp[] = {NULL};

		if (strcmp(argv[0], "./ppid") == 0)
		{
			parent_pid = getpid();

			printf("%u \n", parent_pid);

		}

		if (execve(argv[0], argv, envp) == -1)
		{
			perror("Execve did not execute");

		}



		printf("#cisfun$");
	}

	return (0);
}


