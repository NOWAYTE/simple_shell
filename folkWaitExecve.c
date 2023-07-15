#include<stdio.h>
#include<unistd.h>
/**
 * main - function that executes the command ls -l /tmp 
 * in 5 different processes
 *
 * Return: Always 0 (success)
 *
 */

int main(void)
{
	int id, i;

	char *cmd = "/usr/bin/ls";

	char *argv[] = {"/usr/bin/ls", "-l", "/tmp", NULL};

	char *envp[] = {NULL};

	id = fork();

	if (id == -1)
	{
		perror("Error");

		return (1);

	}

	for (i = 0; i < 5; i++)
	{
		if (id == 0)
		{
			execve(cmd, argv, envp);
			perror("Error");

			return (1);

		}
		else
		{
			id = fork();

			if (id == -1)

			{
				perror("Error");

				return (1);

			}
		}

	}

	return (0);

}
