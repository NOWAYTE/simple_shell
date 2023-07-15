#include<stdio.h>
#include<unistd.h>
/**
 * main - Entry to the program 
 *
 * Return: Always 0 (success)
 *
 */

int main(void)
{
	char cmd[] = "/usr/bin/ls";

	char *argv[] =  {"ls", "-l", NULL};

	char *envp[] = {NULL};

	printf("Start of execv call %s: \n", cmd);

	printf("================================================\n");

	if (execve(cmd, argv, envp) == -1)
	{
		perror("Execve did not execute");

	}

	printf("Something went wrong");

	return (0);

}

