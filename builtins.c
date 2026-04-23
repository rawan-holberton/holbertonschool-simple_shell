#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * is_builtin - check and execute builtins
 * @argv: arguments array
 * @line: input line to free if needed
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int is_builtin(char **argv, char *line)
{
	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		handle_exit(argv, line, 0);
		return (1);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		handle_env();
		free(line);
		return (1);
	}

	return (0);
}
