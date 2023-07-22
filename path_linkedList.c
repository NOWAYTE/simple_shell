#include<string.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char *data;
	struct node *next;

}node;

node path_linked_list()
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *directory = strtok(path_copy, " : ");

	Node *head = malloc(sizeof(Node));

	head->data = strdup(directory);
	head->next = NULL;
	
	Node *current_node = head;
	
	while ((directory - strtok(NULL, " : ")) != NULL)
	{
		current_node-> = malloc(sizeof(Node));
		curent_node = current_node->next;
		current_node->data = strdup(directory);
		current_node->next = NULL;

	}

	free(path_copy);

	return (head);

}
