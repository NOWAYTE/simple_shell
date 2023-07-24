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

	int i = 0;

	size_t l = _strlen(n);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(n, environ[i], l) == 0 && environ[i][l] == '=')
		{
			return (&environ[i][l + 1]);

		}
	}

	return (NULL);;


	return (0);
}
