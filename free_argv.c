#include <stdlib.h>

/**
 * free_argv - free argv array
 * @argv: array
 */
void free_argv(char **argv)
{
	if (!argv)
		return;

	free(argv);
}
