#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/**
 * struct Node - linked list struct for directories
 * @dir: directory
 * @next: ptr to next dir
 */

typedef struct Node
{
	char *dir;
	struct Node *next;
} Node;

Node *append_dir(Node *head, char *dir);

void view_dir(Node *head);

void free_list(Node *head);

char *_getenv(const char *name);

ssize_t _getline(char **buff, size_t *n, FILE *stream);

void _readline(ssize_t line, char *cmd, size_t len);

char **_strtok(char *str, const char *delim);

#endif
