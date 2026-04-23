#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * path_resolver - resolves command path
 * @cmd: command name
 *
 * Return: full path or NULL
 */
char *path_resolver(char *cmd)
{
	char *path_env, *path_copy, *token, *full_path;
	int len;

	if (!cmd)
		return (NULL);

	if (access(cmd, X_OK) == 0)
		return (cmd);

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
			return (NULL);

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
