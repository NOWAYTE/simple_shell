#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>


void _print(char *string, int stream);
size_t _strlen(const char *c);
char *_strdup(const char *c);
char *_strcpy(char *d, const char *s);
int _getchar();

#endif
