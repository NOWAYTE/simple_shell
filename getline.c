#include<stdio.h>
#include<stdlib.h>

/**
 * my_getline - function that reads a line from a file 
 * pointer and stores it in a charcter array
 *
 * @ptr - pointer to a buffer where text is stored
 * @len: used to tracj the size of the character array
 *
 * @stream: file pointer which specifies the file from 
 * which the line will read
 *
 * Return: returns the length of a line 
 */

size_t my_getline(char *ptr, size_t *len, FILE *stream)
{
	size_t i = 0;
	 char ch;

	 /**
	  * Note : for this my_getline function the size of array
	  * doesnt change if so needed use realloc to declare 
	  * a new size of array
	  */
	while ((ch = getc(stream)) != EOF )
	{
		if (ch != EOF)
		{
			if (i < *len - 1)
			{
				ptr[i++] = ch;
			}
		}

	}

	if (ch == '\n')
	{
		ptr[i++] = ch;
	}

	ptr[i] = '\0';

	*len = i;

	return (i);

}
