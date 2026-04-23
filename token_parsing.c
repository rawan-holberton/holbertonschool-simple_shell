#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * token_parsing - split line into argv
 * @line: input string
 *
 * Return: argv array
 */
char **token_parsing(char *line)
{
	char **argv;
	char *token;
	int i = 0;
	int size = 64;

	argv = malloc(sizeof(char *) * size);
	if (!argv)
		return (NULL);

	token = strtok(line, " ");
	while (token)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	argv[i] = NULL;
	return (argv);
}
