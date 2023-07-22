#include<stdio.h>

int main(int argc, char **argv, char **env)
{
	extern char **environ;

	printf("%p\n", environ);

	printf("%p\n", env);


	return (0);

}
