#include "shell.h"

/**
 * main – Entry to the program
 * description: main function
 * @argc: argument count 
 * @argv: argument vector
 * Return: Always 0 (success)
 */
int main(int argc, char **argv)
{
	s_loop(argc, argv);
	return (0);
}

/**
 * s_loop – runs the shell repeatedly
 * description: exit terminates this loop
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int s_loop(int argc, char **argv)
{
	int userinput;
	char *buffer = NULL;
	size_t bufsize;
	char *prompt = "$ ";
	char **path_tokens = NULL;
	char *executable = NULL;

	(void) argc;

	buffer = NULL;
	while (1)
	{
		/* buffer = malloc(sizeof(char) * bufsize);*/
		   /* if (buffer == NULL) */
		   /* perror("Malloc failure\n"); */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, s_len(prompt));
		}
		userinput = getline(&buffer, &bufsize, stdin);
		if (userinput == -1)
			break;
		argv = token(buffer);
		if (argv[0] == NULL)
			continue;
		if (fin_fun(argv, buffer) == 1)
		{
			free(argv);
			continue;
		}
		path_tokens = _get_env("PATH");
		executable = s_dir(argv, path_tokens);
		exec(executable, argv);
		d_free(path_tokens);
		if (argv[0][0] != '/')
			free(executable);
		free(argv);
	}
	free(buffer);
return (0);
}

/**
 * token - token user input
 * description: to breakdown command
 * @userinput:command
 * Return: 0
 */
char **token(char *userinput)
{
	int token_inc = 0;
	char *token = NULL;
	char **argv = NULL;
	int tokencount = 0;
	int i;

	strtok(userinput, "\n");
	for (i = 0;userinput[i] != '\0'; i++)
	{
		if (userinput[i] == ' ')
		{
			tokencount++;
		}
	}
	argv = malloc(8 * (tokencount + 2));
	if (argv != NULL)
	{
		token_inc = 0;
		token = strtok(userinput, " ");
		while (token_inc < (tokencount + 1))
		{
			argv[token_inc] = token;
			token = strtok(NULL, " ");
			token_inc++;
		}
		argv[token_inc] = NULL;
	}

	/*free(userinput);*/
	return (argv);
}

/**
 * exec - executes the command given
 * description: by forking and execing
 * @asdf: asdf
 * @argv: argv
 * Return: 0
 */

int exec(char *asdf, char **argv)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror("Fork failure\n");
	if (child_pid == 0)
	{
		execve(asdf, argv, environ);
	}
	else
	{
		wait(NULL);
	}
	/*free(argv);*/
	return (0);
}


/**
 * fin_fun - for builtins
 * description: searches and compares to see if the command is a builtin
 * @argv: argv
 * @buffer: buffer
 * Return: 0
 */
int fin_fun(char **argv, char *buffer)
{
	int i;

	builtins arr[] = {
		{"cd", s_cd},
		{"env", s_env},
		{"exit", s_exit},
		{"setenv", s_setenv},
		{"unsetenv", s_unsetenv},
		{"alias", sh_alias},
		{'\0', NULL}
	};

	if (argv != NULL)
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			s_exit(argv, buffer);
			return (1);
		}
		for (i = 0; arr[i].func; i++)
		{
			if (_strcmp(argv[0], arr[i].argv) == 0)
			{
				arr[i].func();
				return (1);
			}
		}
	}
	return (0);
}

