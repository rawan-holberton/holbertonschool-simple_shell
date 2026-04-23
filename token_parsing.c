#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * token_parsing - split line
 * @line: input
 *
 * Return: argv
 */
char **token_parsing(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 64);
	if (!argv)
		return (NULL);

	token = strtok(line, " \t");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	return (argv);
}
