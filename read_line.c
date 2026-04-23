#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_line - reads input from stdin
 *
 * Return: line (malloced) or NULL on EOF
 */
char *read_line(void)
{
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
                free(line);
                return (NULL);
        }

        /* remove newline */
        if (line[read - 1] == '\n')
                line[read - 1] = '\0';

        /* ignore empty line */
        if (line[0] == '\0')
        {
                free(line);
                return (NULL);
        }

        return (line);
}
