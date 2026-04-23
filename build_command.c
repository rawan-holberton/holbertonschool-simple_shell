#include <stdlib.h>
#include <unistd.h>

/**
 * build_command - check if command exists
 * @cmd: command name
 *
 * Return: same cmd or NULL if not found
 */
char *build_command(char *cmd)
{
		if (!cmd)
				return (NULL);

		/* if already full path */
		if (cmd[0] == '/')
		{
				if (access(cmd, X_OK) == 0)
						return (cmd);
				return (NULL);
		}

		/* simple PATH resolution (minimal) */
		if (access(cmd, X_OK) == 0)
				return (cmd);

		return (NULL);
}
