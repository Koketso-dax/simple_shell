#include "shell.h"
/**
 * append_dir - will add dir to linked list
 * @head: ptr to list head
 * @dir: directory
 * Return: ptr to newly added item
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
/**
 * view_dir - will print directories in linked list
 * @head: ptr to head list item
 */
void view_dir(Node *head)
{
	while (head)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}
}
/**
 * free_list - frees list of directories in memory
 * @head: ptr to head of list
 */
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
