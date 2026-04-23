#include "shell.h"
#include <stdio.h>

/**
  * print_not_found - prints an error when a command is not found
  * @prog_name: name of the program
  * @line_count: number of the command (line count)
  * @command: command that was not found
  */

void print_not_found(char *prog_name, int line_count, char *command)
{
	fprintf(stderr, "%s: %d: %s: not found\n",
			prog_name, line_count, command);
}
