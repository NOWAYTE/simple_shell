#include "shell.h"
/**
 * _strcmp - implementation of the strcmp function
 *
 * @s1: string for comparison
 * @s2: string for comparison
 *
 * Return: return 0 if string are similar 
 *
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}

	return (s1 - s2);

}
