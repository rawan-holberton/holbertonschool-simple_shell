#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>

extern char **environ;

/* PARSING */
char *read_line(void);
char **token_parsing(char *line);
void free_argv(char **argv);

/* BUILTINS */
int is_builtin(char **argv);

/* EXECUTION */
void exec_command(char **argv);
char *path_resolver(char *cmd);

#endif
