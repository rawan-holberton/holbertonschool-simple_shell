#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - simple shell loop
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *line;
	char **argv;
	int line_count = 0;

	(void)ac;

	while (1)
	{
		line_count++;

		if (isatty(STDIN_FILENO))
			printf("($) ");

		line = read_line();
		if (!line)
			break;

		argv = token_parsing(line);
		if (!argv)
		{
			free(line);
			continue;
		}

		/* BUILTINS */
		if (argv[0] && strcmp(argv[0], "exit") == 0)
		{
			handle_exit(argv, line, 0);
		}
		else if (argv[0] && strcmp(argv[0], "env") == 0)
		{
			handle_env();
		}
		else
		{
			exec_command(argv, av[0], line_count);
		}

		free_argv(argv);
		free(line);
	}

	return (0);
}
