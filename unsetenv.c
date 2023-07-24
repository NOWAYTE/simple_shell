#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void count()
{
	extern char *environ;
	count = 0;
	while (environ)
	{
		count++;

	}

}
int _unsetenv(const char *name)
{
	extern char *environ;
	int i = 0;


	char *n_environ = NULL;

	while (environ)
	{
		if (strncmp(*environ, name , strlen(name)) == 0)
		{
			n_environ = malloc(sizeof(char *) * (count - 1));

			if (n_environ == NULL)
			{
				return (-1);

			}
		}
	}
	
	while (environ)
	{
		if (strncmp(*environ, name, strlen(name)) != 0)
		{
			n_environ[i++] = *environ;

		}
	}


	free(environ);

	environ = n_environ;
	count--;

	return (0);

}
