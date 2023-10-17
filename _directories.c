#include "shell.h"
/**
 * directory related functions
 */

Node *append_dir(Node *head, char *dir)
{
	Node *_node = malloc(sizeof(Node));

	if (_node == NULL)
	{
		printf("Error\n");
		exit(1);
	}

	_node->dir = strdup(dir);
	_node->next = head;
	return (_node);
}
void view_dir(Node *head)
{
	while (head)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}
}
void free_list(Node *head)
{
	Node *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}
}
