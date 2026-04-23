#include "shell.h"
#include <stdlib.h>

/**
 * free_argv - free argv
 * @argv: array
 */
void free_argv(char **argv)
{
	if (argv)
		free(argv);
}
