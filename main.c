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

		/* HANDLE BUILTINS */
		if (is_builtin(argv))
		{
			free(line);
			free_argv(argv);
			continue;
		}
		
		if (!argv[0])
        {
            free(line);
            free_argv(argv);
            continue;
        }

       
        exec_command(argv, "./hsh", 0);


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
