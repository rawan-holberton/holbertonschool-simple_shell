#include "shell.h"
#include <stdlib.h>

/**
 * handle_exit - exit shell
 */
int handle_exit(char **argv, char *line, int status)
{
	(void)argv;

	free(line);
	exit(status);
}
