#include "shell.h"
/**
 * _strdup - implemetation of the strdup function 
 *
 * @c: pointer to a string
 *
 * Return: returns a pointer to a new string 
 */

char *_strdup(const char *c)
{
	char *x;

	x = malloc(_strlen(c) + 1);

	if (x == NULL)
	{
		return (NULL);

	}

	_strcpy(x, c);

	return (x);

}
