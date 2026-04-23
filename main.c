#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * shell_loop - main loop of the shell
 * @prog_name: program name (argv[0])
 */
void shell_loop(char *prog_name)
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

		exec_command(argv, prog_name, line_count);

		free(line);
		free_argv(argv);
	}
	free(line);
}

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	(void)ac;

	shell_loop(av[0]);
	return (0);
}
