#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * path_resolver - resolve command path using PATH
 * @cmd: command name
 *
 * Return: full path or NULL if not found
 */
char *path_resolver(char *cmd)
{
	char *path, *dup, *token, *full;
	int len;

	if (!cmd)
		return (NULL);

	if (access(cmd, X_OK) == 0)
		return (cmd);

	path = getenv("PATH");
	if (!path)
		return (NULL);

	dup = strdup(path);
	if (!dup)
		return (NULL);

	token = strtok(dup, ":");
	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full = malloc(len);
		if (!full)
			return (free(dup), NULL);

		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);

		if (access(full, X_OK) == 0)
			return (free(dup), full);

		free(full);
		token = strtok(NULL, ":");
	}
	free(dup);
	return (NULL);
}
