#include "shell.h"

/**
 * _strcmp - compares strings
 * @s1: string
 * @s2: string
 * Return: 0 on success
**/
int _strcmp(char *s1, char *s2)
{
	int k = 0, l = 0;


	for (; s1[k] != '\0' || s2[l] != '\0'; k++, l++)
	{

		if (s1[k] != s2[l])
		{

			return (s1[k] - s2[l]);
		}
	}


	return (0);
}

/**
 * s_len - gets length
 *
 * @s: a string
 *
 * Return: length
**/
int s_len(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{}

		return (x);
}

/**
 * _strdup - duplicates  string
 * @s: string
 *
 * Return: returns  pointer to new
**/
char *_strdup(char *s)
{
	char *d = NULL;
	int i;
	int l = 0;

	if (s == NULL)

		return (NULL);

	for (l = 0; s[l] != '\0'; l++)
		;
	d = malloc((l + 1) * sizeof(char));
	if (d == NULL)

		return (NULL);

	for (i = 0; i <= l; i++)

		d[i] = s[i];



	return (d);

}

/**
 * _putchar - writes a  character
 * @c: character
 *
 * Return: the character
**/
int _putchar(char c)
{

	return (write(1, &c, 1));
}

/**
 * d_free -  pointers
 * @d_poin: a double pointer
 * Return: void
**/
void d_free(char **d_poin)
{
	int i = 0;


	while (d_poin[i])
	{
		free(d_poin[i]);

		i++;


	}


	free(d_poin);
}

