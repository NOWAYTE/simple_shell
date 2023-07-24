#include "shell.h"
/**
 * _strlen - implementation of the strlen function
 *
 * @c: pointer to a string
 *
 * Return: returns the length of the string 
 */

size_t _strlen(const char *c)
{
	size_t i = 0;

	while (*c)
	{
		i++;
		c++;
	}

	return (i);

}
