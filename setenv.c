#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;

	extern char **environ;

	char *entry;
	entry = malloc(strlen(name) + strlen(value) + 2);

	if  (entry == NULL)
	{
		return (-1);

	}

	sprintf(entry, "%s=%s", name, value);

	while (environ)
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
		environ++;
		i++;

	}

	environ = realloc(environ, sizeof(char *) * (i + 1));

	if (environ == NULL)
	{
		free(environ);

		return (-1);

	}

	environ[i++] = entry;

	return (0);

}
