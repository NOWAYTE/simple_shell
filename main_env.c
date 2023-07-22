#include<stdio.h>

int main(__attribute((unused))int argc, __attribute__((unused))char **argv, char **env)
{
	unsigned int i = 0;

	while(env[i] != NULL)
	{
		printf("%s \n", env[i]);
		i++;

	}


	return (0);

}
