#include "shell.h"
#include <stdio.h>

/**
 * handle_env - print environment variables
 */
void handle_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
