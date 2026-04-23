#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * shell_loop - main loop
 */
void shell_loop(void)
{
	char *line = NULL;
	char **argv = NULL;
	int line_count = 0;

	while (1)
	{
		line_count++;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_line();
		if (!line)
			break;

		argv = token_parsing(line);
		if (!argv || !argv[0])
		{
			free(line);
			free_argv(argv);
			continue;
		}

		if (is_builtin(argv, line))
		{
			free_argv(argv);
			continue;
		}

		exec_command(argv, "./hsh", line_count);

		free(line);
		free_argv(argv);
	}
	free(line);
}

/**
 * main - entry
 *
 * Return: 0
 */
int main(void)
{
	shell_loop();
	return (0);
}
