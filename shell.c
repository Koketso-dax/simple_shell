#include "shell.h"
/**
 * main - will run an instance of simple_shell
 * Return: 0 on success. 1 on fail.
 */
int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t line = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		line = getline(&cmd, &len, stdin);
		_readline(line, cmd, len);
		free (cmd);
		cmd = NULL;
		len = 0;
	}
	return (0);
}
