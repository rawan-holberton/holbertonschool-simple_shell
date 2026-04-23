#include "shell.h"
#include <stdio.h>

/**
 * print_not_found - error
 */
void print_not_found(char *prog, int line, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog, line, cmd);
}
