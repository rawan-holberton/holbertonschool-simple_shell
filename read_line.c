#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_line - read a line from stdin
 *
 * Return: allocated line or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t r;

	r = getline(&line, &len, stdin);
	if (r == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[r - 1] == '\n')
		line[r - 1] = '\0';

	return (line);
}
