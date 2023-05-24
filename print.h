#ifndef ERROR_MSG_H
#define ERROR_MSG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err_cmd_not_found(char *program_name, char *command, int loop);
void _printf(char *str);
void print_env(char **envp);

#endif
