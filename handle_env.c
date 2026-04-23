#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * handle_env - print env
 */
void handle_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
