#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(void)
{
	DIR *directory;

	struct dirent *entry;


	directory = opendir(".");

	if (directory == NULL)
	{
		return (-1);

	}

	while ((entry = readdir(directory)) != NULL)
	{
		printf("%s \n", entry->d_name);


	}

	if (closedir(directory) == -1)
	{
		perror("Error");

	}

	return (0);
}
