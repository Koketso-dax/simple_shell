#include "shell.h"
/**
 * functions for enviroment variables
 */

char *_getenv(const char *name)
{
	char **env = environ;
	char *envar;
	int i;

	while (*env != NULL)
	{
		envar = *env;
		i = 0;

		while (envar[i] != '=' && envar[i] != '\0')
		{
			i++;
		}
		if (envar[i] == '=')
		{
			if (strncmp(envar, name, i) == 0)
			{
				return (&envar[i + 1]);
			}
		}
		env++;
	}
	return (NULL);
}
