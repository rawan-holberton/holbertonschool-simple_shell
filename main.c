#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * shell_loop - main loop of the shell
 *
 * Description: reads input, parses it, handles builtins,
 * resolves PATH and executes commands.
 *
 * Return: void
 */
void shell_loop(void)
{
	char *line;
	char **argv;
	char *cmd_path;

	while (1)
	{
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
		if (is_builtin(argv))
		{
			free(line);
			free_argv(argv);
			continue;
		}
		cmd_path = path_resolver(argv[0]);

		if (!cmd_path)
		{
			fprintf(stderr, "./hsh: %s: not found\n", argv[0]);
			free(line);
			free_argv(argv);
			continue;
		}

		argv[0] = cmd_path;
		exec_command(argv);
		free(line);
		free_argv(argv);
	}
}

/**
 * main - entry point
 *
 * Return: 0 on success
 */
int main(void)
{
	shell_loop();
	return (0);
}
