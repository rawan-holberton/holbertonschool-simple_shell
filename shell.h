#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

/* GLOBAL */
extern char **environ;

/* INPUT */
char *read_line(void);

/* PARSING */
char **token_parsing(char *line);
void free_argv(char **argv);

/* EXECUTION */
void exec_command(char **argv, char *prog_name, int line_count);
char *path_resolver(char *cmd);

/* BUILTINS */
int handle_exit(char **argv, char *line, int status);
void handle_env(void);
int is_builtin(char **argv);

/* ERRORS */
void print_not_found(char *prog_name, int line_count, char *command);

#endif
