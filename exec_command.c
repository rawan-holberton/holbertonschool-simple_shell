#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * exec_command - execute command
 */
void exec_command(char **argv, char *prog_name, int line_count)
{
	pid_t pid;
	char *path;

	path = path_resolver(argv[0]);
	if (!path)
	{
		print_not_found(prog_name, line_count, argv[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
		return;

	if (pid == 0)
	{
		execve(path, argv, environ);
		perror(prog_name);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	if (path != argv[0])
		free(path);
}
