#ifndef HEADER_H
#define HEADER_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <stddef.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct builtins - struct with builtin commands
 * @argv: arg passed as command
 * @func: correlations function
 * description: this is to handle the builtins
 */
typedef struct builtins
{
	char *argv;
	int (*func)();
} builtins;

char **token(char *userinput);

int s_len(char *s);

int s_loop(int argc, char **argv);

int exec(char *asdf, char **argv);

int fin_fun(char **argv, char *buffer);

int s_exit(char **argv, char *buffer);

int s_cd(char **argv);

int s_env(void);

char *_strcat(char *dest, char *src);

char *s_dir(char **argv, char **path_tokens);

int _strcmp(char *s1, char *s2);

char *executable_maker(char *asdf, char **argv);

void d_free(char **dubbie_pointie);

int _putchar(char c);

char _strchr(char *s, char c);

char *_strdup(char *str);

char **_env_parser(char *name);

char **_get_env(char *env);

extern char **environ;

int s_setenv(char **argv);

int s_unsetenv(char **argv);

int sh_alias(char **argv);

#endif /* HEADER_H */

