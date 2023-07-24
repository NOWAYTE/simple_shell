#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int _count()
{
	int count = 0;
	extern char **environ;

	while (*environ)
	{
		count++;
		environ++;

	}

	return (count);

}

int _setenv(const char *name, const char *value, int overwrite)
{

	extern char **environ;

	int count = _count();

	char *entry;
	entry = malloc(strlen(name) + strlen(value) + 2);

	if  (entry == NULL)
	{
		return (-1);

	}

	sprintf(entry, "%s=%s", name, value);

	while (*environ)
	{
		if (strncmp(*environ, name, strlen(name)) == 0)
		{
			if (overwrite)
			{
				*environ = entry;

				return (0);

			}
			else
			{
				free(entry);

				return (-1);

			}

		}
		(*environ)++;

	}

	environ = realloc(environ, sizeof(char *) * (count + 1));

	if (environ == NULL)
	{
		free(environ);

		return (-1);

	}

	environ[count++] = entry;

	return (0);

}
