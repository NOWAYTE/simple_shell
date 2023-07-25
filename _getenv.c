#include "shell.h"
/**
 * _getenv - implementation of the getenv function 
 *
 * @name: pointer to string
 *
 * Return: returns the value of the name
 *
 */


char *_getenv(const char *n)
{
	extern char **environ;
	
	char *dir;

	int i = 0;

	size_t l = _strlen(n);

	char *path = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(n, environ[i], l) == 0 && environ[i][l] == '=')
		{
			path = (&environ[i][l + 1]);

			break;

		}
	}

	if (path == NULL)
	{
		return (NULL);

	}

	dir = strchr(path, ':');

	if (dir != NULL)
	{
		*dir = '\0';
	}



	return (path);;


	return (0);
}
