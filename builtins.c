#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * is_builtin - handle builtins
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
