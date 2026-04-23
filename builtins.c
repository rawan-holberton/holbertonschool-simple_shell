#include "shell.h"
#include <stdlib.h>

/**
 * handle_exit - Exits the shell with a given status
 * @argv: Array of arguments passed to the shell (unused)
 * @line: Pointer to the input line to be freed before exiting
 * @status: Exit status to be returned to the system
 *
 * Description: This function frees the allocated memory for the input
 * line and terminates the shell process using the provided exit status.
 *
 * Return: This function does not return (terminates the process)
 */

int handle_exit(char **argv, char *line, int status)
{
	(void)argv;

	free(line);
	exit(status);
}
