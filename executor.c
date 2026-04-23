#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * exec_command - execute a command
 * @argv: arguments array
 * @prog_name: program name
 * @line_count: line number
 */
void exec_command(char **argv, char *prog_name, int line_count)
{
	pid_t pid;
	char *path;

	if (!argv || !argv[0])
		return;

	path = argv[0];

    if (access(path, X_OK) != 0)
    {
    	print_not_found(prog_name, line_count, argv[0]);
    	return;
    }

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
