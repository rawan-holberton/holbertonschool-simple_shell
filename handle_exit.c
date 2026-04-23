#include "shell.h"
#include <stdlib.h>

/**
 * handle_exit - exits the shell
 * @argv: arguments array
 * @line: input line to free
 * @status: exit status
 *
 * Return: does not return
 */
int handle_exit(char **argv, char *line, int status)
{
	(void)argv;

	free(line);
	exit(status);
}
