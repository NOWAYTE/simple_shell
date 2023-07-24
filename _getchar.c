#include "shell.h"
/**
 * _getchar - implementation of the getchar function
 *
 * Return: return an integer 
 *
 */

int _getchar(void)
{
	char x;

	if (read(0, &x, 1) == 1)
	{
		return (x);

	}
	else
	{
		return (EOF);
	}

}
