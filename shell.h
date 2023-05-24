#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

char *read_input(int *exit_code);
int run_shell(char **params, char **paths, char *prog_nam, int lp, char **env);
int shell_loop(char *program_name, char **paths, char **env);

#endif

