#include "shell.h"
/**
 * s_exit -exits the shell
 *
 * @argv: argumnet vector
 *
 * @buf: buffer
 *
 *
 * Return: 0
 */

int s_exit(char **argv, char *buf)
{
	free(argv);
	free(buf);
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

	char *st = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			st = (&(environ[i][j]));

			write(STDOUT_FILENO, st, s_len(st));

			break;
		}

		_putchar('\n');
	}
	return (0);
}
/**
* s_setenv - sets env
* @argv: argument vector
*
* Return: 0
*
*/


int s_setenv(char **argv)
{
	argv = argv;
	return (0);
}

/**
* s_unsetenv - unsets env
* @argv: argument vector
*
*
* Return: 0
*/


int s_unsetenv(char **argv)
{
	argv = argv;
	return (0);
}

/**
 * s_cd - changes directory
 *
 * @argv: argument vector
 *
 *
 * Return: 0
**/
int s_cd(char **argv)
{
	argv = argv;
	return (0);
}
