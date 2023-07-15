#include<stdio.h>
#include<stdlib.h>
/**
 * main - program that prints all the arguments 
 *
 * @argc: argument count 
 * @argv: argumnet vector
 *
 * Return: Always 0 (success)
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);

		i++;
	}

	return (0);

}
