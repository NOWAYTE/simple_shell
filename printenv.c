#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *entry = NULL;
	char *path;
	char *filename;
	int i;

	if (argc < 2)
	{
		printf("Usage: whicih filename ... \n");

		return (1);

	}

	for (i = 1; i < argc; i++)
	{
		filename = argv[1];

		path = getenv("PATH");

		dir = opendir(path);

		while ((entry == readdir(dir)) != NULL)
		{
			if (strcmp(entry->d_name, filename) == 0)
			{
				printf("%s \n", entry->d_name);
				break;

			}
		}

		closedir(dir);

		if (entry == NULL)
		{
			printf("File not found : %s\n", filename);
		}
	}

	return (0);

}
