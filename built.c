#include "shell.h"

/**
 * _get_env - gets env
 *
 * @env: env
 * Return: NULL on failure
**/
char **_get_env(char *env)
{

	int in;
	int out;

	char *n = NULL;

	for (out = 0; environ[out] != NULL; out++)
	{


		for (in = 0; environ[out][in] != '='; in++)


		{


			if (environ[out][in] != env[in])
				break;
			if (environ[out][in] == env[in])
			{


				if (env[in + 1] == '\0' && environ[out][in + 1] == '=')
				{
					n = _strdup(&(environ[out][in + 2]));
					return (_env_parser(n));
				}
			}
		}
	}


	return (NULL);
}

/**
 * _env_parser- gets path and tokenizes
 * @name: PATH
 * Return: an array
**/
char **_env_parser(char *name)
{
	int t_inc;
	int t_count;

	char *token = NULL;

	int i;
	char **y = NULL;
	char *n_st = name;

	t_count = 0;


	for (i = 0; name[i] != '\0'; i++)
	{
		if (name[i] == ':')
		{
			t_count++;
		}
	}
	y = malloc(sizeof(char *) * (t_count + 2));

	if (y != NULL)
	{

		t_inc = 0;
		token = strtok(name, ":");


		while (t_inc < (t_count + 1))
		{
			y[t_inc] = _strdup(token);

			token = strtok(NULL, ":");
			t_inc++;


		}
	y[t_inc] = NULL;


	}


	free(n_st);
	return (y);
}

