#include "shell.h"
/**
 * main - Entry to the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 (succees)
 *
 */
int main(int argc, char **argv)
{
	s_loop(argc, argv);
	return (0);
}
/**
 * s_loop - runs the loop repeatedly
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: NUll
 */
int s_loop(int argc, char **argv)
{
	int user;

	char *buf = NULL;
	size_t buf_s;
	char *prompt = "$ ";
	char **t_path = NULL;
	char *execut = NULL;

	(void) argc;

	buf = NULL;
	while (1)
	{
		/* buf = malloc(sizeof(char) * bufsize);*/
		   /* if (buffer == NULL) */
		   /* perror("Malloc failure\n"); */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, s_len(prompt));
		}
		user = getline(&buf, &buf_s, stdin);
		if (user == -1)
			break;

		argv = token(buf);

		if (argv[0] == NULL)
			continue;
		if (fin_fun(argv, buf) == 1)
		{
			free(argv);
			continue;

		}
		t_path = _get_env("PATH");

		execut = s_dir(argv, t_path);

		exec(execut, argv);

		d_free(t_path);
		if (argv[0][0] != '/')

			free(execut);

		free(argv);
	}
	free(buf);
return (0);
}

/**
 * token - token user
 * @user: command
 * Return: 0
 *
 */

char **token(char *user)
{
	int t_inc = 0;
	char *token = NULL;
	char **argv = NULL;
	int t_count = 0;
	int i;

	strtok(user, "\n");
	for (i = 0; user[i] != '\0'; i++)
	{
		if (user[i] == ' ')
		{
			t_count++;
		}
	}
	argv = malloc(8 * (t_count + 2));
	if (argv != NULL)
	{
		t_inc = 0;
		token = strtok(user, " ");
		while (t_inc < (t_count + 1))
		{
			argv[t_inc] = token;
			token = strtok(NULL, " ");
			t_inc++;
		}
		argv[t_inc] = NULL;
	}

	/*free(user);*/
	return (argv);
}

/**
 * exec - executes command
 * @as: pointer charcter
 * @argv: pointer to string
 *
 * Return: 0
 */

int exec(char *as, char **argv)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)

		perror("Fork failure\n");
	if (child_pid == 0)
	{

		execve(as, argv, environ);
	}
	else
	{
		wait(NULL);
	}

	/*free(argv);*/
	return (0);
}


/**
 * fin_fun - searches and compare
 * @argv: argv
 *
 * @buf: buffer
 * Return: 0
 *
 */

int fin_fun(char **argv, char *buf)
{
	int x;



	builtins st[] = {
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
			s_exit(argv, buf);

			return (1);

		}
		for (x = 0; st[x].func; x++)
		{
			if (_strcmp(argv[0], st[x].argv) == 0)
			{

				st[x].func();

				return (1);
			}

		}


	}


	return (0);

}

