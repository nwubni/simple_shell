#ifndef STR_LIB_H
#define STR_LIB_H

#include <stdlib.h>
#include <string.h>

int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, int n);
void _strncpy(char *dest, const char *src, int n);
void _strcat(char *dest, const char *src);

#endif
