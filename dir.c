#include "shell.h"
/**
 * s_dir - searches through the PATH for a matching command
 * @argv: array of strings containing our tokend arguments
 * @path_tokens: array of strings containing our tokend PATH
 * Return: modified argv[0]
**/
char *s_dir(char **argv, char **path_tokens)
{
	struct dirent *dir_store;
	DIR *deer = NULL;
	int i;
	char *asdf = NULL;
	char *store = NULL;

	if (argv[0][0] == '/')
		return (argv[0]);
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		deer = opendir(path_tokens[i]);
		while ((dir_store = readdir(deer)) != NULL)
		{
			if (_strcmp(argv[0], dir_store->d_name) == 0)
			{
				asdf = path_tokens[i];
				store = executable_maker(asdf, argv);
				closedir(deer);
				return (store);
			}
		}
	closedir(deer);
	}
	return (NULL);
}

/**
 * executable_maker- modifies argv[0] into an executable
 * @asdf: stores the path of the correct directory
 * @argv: argv[0] is concatenated to asdf
 * Return: modified asdf
**/
char *executable_maker(char *asdf, char **argv)
{
	char *addslash = NULL;
	char *newcmd = NULL;

	addslash = _strcat(asdf, "/");
	newcmd = _strcat(addslash, argv[0]);
	free(addslash);
return (newcmd);

}
/**
*_strcat- entry point
*description: concatenates two strings
*@dest: string to copy to
*@src: string to be copied
*Return: dest
**/
char *_strcat(char *dest, char *src)
{
	int a, p, x;
	char *newcmd = NULL;

	for (p = 0; dest[p] != '\0'; p++)
	{}
	for (a = 0; src[a] != '\0'; a++)
	{}
	newcmd = malloc(sizeof(char) * (a + p + 1));
	for (x = 0; x < p; x++)
	{
		newcmd[x] = dest[x];
	}
	for (x = 0; x < a; x++)
	{
		newcmd[x + p] = src[x];
	}
	newcmd[x + p] = '\0';
	return (newcmd);
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

#include "shell.h"

/**
 * s_exit - this exits the shell
 * description: exit builtin
 * @argv: argv
 * @buffer: buffer
 * Return: 0
 */

int s_exit(char **argv, char *buffer)
{
	free(argv);
	free(buffer);
	exit(0);
}

/**
 * s_env- prints the environment details
 * description: env builtin
 * Return: 0
 */
int s_env(void)
{
	int i;
	int j;

	char *string = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			string = (&(environ[i][j]));
			write(STDOUT_FILENO, string, s_len(string));
			break;
		}
		_putchar('\n');
	}
	return (0);
}
/**
* s_setenv - sets the env
* @argv: arguments
* Return: 0
*/
int s_setenv(char **argv)
{
	argv = argv;
	return (0);
}

/**
* s_unsetenv - unsets the env
* @argv: arguments
* Return: 0
*/
int s_unsetenv(char **argv)
{
	argv = argv;
	return (0);
}

/**
 * s_cd - changes current directory
 * @argv: arguments
 * Return: 0
**/
int s_cd(char **argv)
{
	argv = argv;
	return (0);
}

