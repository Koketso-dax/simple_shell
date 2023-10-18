#include "shell.h"

/**
 * _getline - will get a str entered by user and save it to a buffer
 * @buff: str entered
 * @n: ptr to num of bytes
 * @stream: stream type
 * Return: buff me location
 */
ssize_t _getline(char **buff, size_t *n, FILE *stream)
{
	size_t init_size, final_size, len = 0;
	char *line, *new_line;
	int ch;

	if (!buff || !n || !stream)
	{
		exit(1);
	} init_size = *n, line = *buff;
	if (line == NULL)
	{
		line = malloc(init_size);
		if (line == NULL)
		{
			exit(1);
		} *n = init_size;
	}
	while (1)
	{
		ch = fgetc(stream);
		if (ch == EOF || ch == '\n')
		{
			if (len > 0 || (ch == '\n' && init_size > 0))
			{
				line[len] = '\0', *buff = line;
				return (len);
			}
			else if (ch == EOF)
			{
				*buff = NULL, exit(1);
			}
		}
		if (len + 1 >= init_size)
		{
			final_size = init_size * 2, new_line = realloc(line, final_size);
			if (new_line == NULL)
			{
				*buff = NULL, exit(1);
			} line = new_line, *n = final_size;
		} line[len++] = (char)ch;
	}
}

/**
 * _readline - will fork wait and execute cmd
 * @line: line size (-1) if invalid
 * @cmd: cmd str buffer
 * @len: cmd length
 * Return: 0 on success. 1 of fail.
 */
int _readline(ssize_t line, char *cmd)
{
	pid_t child;
	char *argv[4];
	int status;

	if (line == -1)
	{
		return (1);
	}
	child = fork();
	if (child == -1)
	{
		perror("Fork Failed");
		exit(1);
	}
	if (child == 0)
	{
		argv[0] = "/bin/sh", argv[1] = "-c";
		argv[2] = cmd, argv[3] = NULL;
		execve(argv[0], argv, environ);
		perror("Failed to run execve"), exit(1);
	}
	wait(&status);
	return (0);
}
