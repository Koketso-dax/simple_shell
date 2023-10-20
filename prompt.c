#include "shell.h"

/**
 * _splitstr - will split str to [] of ptr to words
 * @input: input str
 * @delim: delimiter
 * Return: Array of ptr
 */
char **_splitstr(const char *input, char *delim)
{
	char **tmp, **words = NULL;
	int count = 0;
	char *token;
	char *copy = strdup(input);

	if (copy == NULL)
	{
		perror("Error");
		exit(1);
	}
	token = strtok(copy, delim);
	while (token != NULL)
	{
		count++;
		tmp = realloc(words, (count + 1) * sizeof(char *));
		if (tmp == NULL)
		{
			perror("Error");
			free(copy);
			exit(1);
		}
		words = tmp;
		words[count - 1] = strdup(token);
		words[count] = NULL;
		token = strtok(NULL, delim);
	}
	free(copy);
	return (words);
}

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
 * @cmd: cmd str buffer.
 */
void _readline(char *cmd)
{
	pid_t child;
	int status;
	char **argv;
	char **env = environ;

	cmd[strcspn(cmd, "\n")] = '\0';
	argv = malloc(3 * sizeof(char *));
	if (argv == NULL)
	{
		perror("Memory allocation failed");
		free(cmd), exit(1);
	}
	argv[0] = "/bin/sh", argv[1] = "-c";
	argv[2] = cmd, argv[3] = NULL;
	child = fork();
	if (child == -1)
	{
		exit(1);
	}
	if (child == 0)
	{
		execve(argv[0], argv, env);
		perror(argv[0]), exit(1);
	}
	else
	{
		wait(&status);
	}
	free(cmd);
	free(argv);
}
