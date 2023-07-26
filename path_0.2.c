#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>

void print_path()
{
	char *path;
	char *token;
	DIR *dp;
	struct dirent *entry;

	path = getenv("PATH");

	token = strtok(path, " : ");

	while (token) {

		for (int i = 0; i < strlen(path); i++) {

			char *dir = path + i;

			dp = opendir(dir);

			if (dp != NULL) {

				while ((entry = readdir(dp)) != NULL) {

					if (access(entry->d_name, X_OK) == 0) {

						if (strcmp(entry->d_name, "ls") == 0) {

							printf("%s", entry->d_name);

						}

					}

				}

			}

		}

		token = strtok(NULL, " : ");

	}
}

int main()
{
	print_path();

	return (0);

}

