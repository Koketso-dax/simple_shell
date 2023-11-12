#include "shell.h"
/**
 * main - will run an instance of simple_shell
 * Return: 0 on success.
 */
int main(void)
{
	char *cmd = NULL, *path, *cpath;
	size_t len = 0;
	ssize_t line = 0;
	char **argv;
	Node *head = '\0';

	while (line != -1)
	{
		is_interactive();
		line = getline(&cmd, &len, stdin);
		if (strcmp(cmd, "exit\n") == 0)
		{
			break;
		}
		argv = _splitstr(cmd);
		if (*argv[0] == '/' || !argv)
		{
			_runline(argv);
		}
		else
		{
			path = _getenv("PATH"), head = join_paths(path);
			cpath = _pathFilename(argv[0], head);
			free(argv[0]), argv[0] = cpath;
			_runline(argv);
		}
	}
	free(cmd);
	freeargs(argv);
	free_list(head);
	return (0);
}
