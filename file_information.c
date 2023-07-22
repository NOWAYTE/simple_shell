#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

/**
 * main - stat example
 * 
 * Return: Always 0;
 *
 */

int main(int argc, char **argv)
{
	unsigned int i;
	struct stat st;

	if (argc < 2)
	{
		printf("Error");

		return (1);

	}

	i = 1;

	while (argv[i])
	{
		printf("%s:", argv[i]);

		if(stat(argv[i], &st) == 0)
		{
			printf("Found \n");

		}

		else
		{
			printf("Not found \n");

		}

		i++;

	}

	return (0);

}
