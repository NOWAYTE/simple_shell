#include<stdio.h>
#include<unistd.h>
/**
 *
 * main -- program that prints the parent process ID
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();

	printf("%u\n", parent_pid);

	return (0);

}
