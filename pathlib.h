#ifndef PATH_LIB_H
#define PATH_LIB_H

#include <sys/stat.h>
#include <unistd.h>

int is_path(char *path);
int file_exists(char *path);
int can_execute(char *path);
char *join_str(char *str1, char *str2, char *str3);
char *find_file(char *file_name, char **paths, int *fm);

#endif

