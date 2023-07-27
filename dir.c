#include "shell.h"
/**
 * s_dir - searches the path
 *
 * @argv: argument vector
 * @path: array of strings
 * Return: argv
**/


char *s_dir(char **argv, char **path)
{
	struct dirent *d_st;
	DIR *d = NULL;
	int i;
	char *a = NULL;
	char *st = NULL;

	if (argv[0][0] == '/')

		return (argv[0]);

	for (i = 0; path[i] != NULL; i++)
	{

		d = opendir(path[i]);

		while ((d_st = readdir(d)) != NULL)
		{

			if (_strcmp(argv[0], d_st->d_name) == 0)
			{

				a = path[i];

				st = executable_maker(a, argv);
				closedir(d);
				return (st);
			}
		}


	closedir(d);

	}

	return (NULL);
}

/**
 * executable_maker- modifies argv
 *
 * @as: stores the path of the correct directory
 * @argv: argv[0] is concatenated to asdf
 * Return: modified asdf
**/
char *executable_maker(char *as, char **argv)
{
	char *ad = NULL;
	char *n = NULL;

	ad = _strcat(as, "/");

	n = _strcat(ad, argv[0]);

	free(ad);

return (n);

}
/**
*_strcat- concatenates two strings
*@d: string to copy to
*@s: string to be copied
*Return: dest
**/

char *_strcat(char *d, char *s)
{
	int a, b, c;
	char *n = NULL;

	for (b = 0; d[b] != '\0'; b++)
	{}
	for (a = 0; s[a] != '\0'; a++)
	{}
	n = malloc(sizeof(char) * (a + b + 1));


	for (c = 0; c < b; c++)
	{
		n[c] = d[c];
	}


	for (c = 0; c < a; c++)
	{
		n[c + b] = s[c];
	}
	n[c + b] = '\0';


	return (n);
}








/**
 * sh_alias - checks for an alias
 * @argv: arguments
 * Return: 0
**/
int sh_alias(char **argv)
{
	argv = argv;
	return (0);
}
