#include "shell.h"
#include <stdlib.h>

int handle_exit(char **argv, char *line, int status)
{
	(void)argv;

	free(line);
	exit(status);
}

#include "shell.h"
#include <string.h>

/**
 * is_builtin - checks and executes built-in commands
 * @argv: argument vector
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int is_builtin(char **argv)
{
		if (!argv || !argv[0])
				return (0);

		if (strcmp(argv[0], "exit") == 0)
		{
				handle_exit(argv, NULL, 0);
				return (1);
		}

		if (strcmp(argv[0], "env") == 0)
		{
				handle_env();
				return (1);
		}

		return (0);
}
