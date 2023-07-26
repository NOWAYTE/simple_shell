#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(void)
{
	DIR *directory;
	char *path;
	char *token;

	struct dirent *entry;

	path = getenv("PATH");

	token = strtok(path, ":");

	while (token)
	{

		token = strtok(NULL, ":");

	}


	directory = opendir("/bin/ls");

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
