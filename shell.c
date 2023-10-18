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
	int x = 0;

	while (x == 0 && line != EOF)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		line = getline(&cmd, &len, stdin);
		x = _readline(line, cmd);
		printf("%s\n", cmd);
		len = 0;
		cmd = NULL;
	}
	free(cmd);
	return (0);
}
