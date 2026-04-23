#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_line - read input
 *
 * Return: line or NULL
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
