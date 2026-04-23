#include "shell.h"
#include <stdlib.h>

/**
 * free_argv - free argument array
 * @argv: array to free
 */
void free_argv(char **argv)
{
	if (argv)
		free(argv);
}
