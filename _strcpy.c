#include "shell.h"
/**
 * _strcpy - Implementation of the strcpy function
 *
 * @d: pointer to buffer where string to be copied
 * @s: pointer to the source of the string 
 * 
 * Return: returns pointer to destination
 *
 */

char *_strcpy(char *d, const char *s)
{
	char *x;

	x = d;
	
	while (*s)
	{
		*x++ = *s++;
	}

	*x = '\0';

	return (d);
}
