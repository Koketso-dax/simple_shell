#include "shell.h"
/**
 * main - will run an instance of simple_shell
 * Return: 0 on success.
 */
int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t line = 0;

	while (line != EOF)
	{
		printf("$ ");
		fflush(stdout);
		line = getline(&cmd, &len, stdin);
		if (line == -1)
		{
			free(cmd);
			exit(1);
		}
		if (line > 0 && cmd[line - 1] == '\n')
		{
			cmd[line - 1] = '\0';
		}
		_readline(cmd);
		cmd = NULL;
		len = 0;
	}
	free(cmd);
	return (0);
}
