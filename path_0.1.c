#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

void path()
{
	char *path;
	char *token;
	DIR *dp;

	struct dirent *entry;

	path = getenv("PATH");

	token = strtok(path, ":");

	while (token)
	{
		dp = opendir(token);

		if (dp != NULL)
		{
			while ((entry = readdir(dp)) != NULL)
			{
				if (strcmp(entry->d_name, "ls") == 0 && access(entry->d_name, X_OK) == 0)
				{
					printf("%s/%s \n", token, entry->d_name);

				}

			}

			closedir(dp);
		}

		token = strtok(NULL, ":");

	}

}

int main()
{
	path();


	return (0);

}
