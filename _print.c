#include "shell.h"
/**
 * prints a string
 * @string - the string to print
 * @stream - stream where to print 
 * 
 * Return: return nothing
 *
 */

void _print(char *string, int stream)
{
	int x;

	for (x = 0; string[x] != '\0'; x++)
	{
		write(stream, &string[x], 1);

	}

}
