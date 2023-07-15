#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * my_strtok - function that spits a sting 
 * into token using the specified delimiter
 *
 * @str: pointer to string 
 *
 * @delim: the delimeter
 *
 * @count: refers to the number of tokens in the array
 *
 * Return: returns an array of each word of the string
 *
 */

char **my_strtok(char *str, char *delim, int *count)
{
	int i = 0;
	char **toks = NULL;

	char *tok == strtok(str, delim);


	while (tok)
	{
		toks = realloc(toks, sizof(char *) * (i + 1));


		toks[i] = tok;
		i++;

		 tok = strtok(NULL, delim);

	}

	*count = i;

	return (toks);

}
