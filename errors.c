#include "shell.h"
#include <stdio.h>

/**
 * print_not_found - prints error when command not found
 * @prog: program name
 * @line: command line count
 * @cmd: command not found
 */
void print_not_found(char *prog, int line, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog, line, cmd);
}
