#include "memlib.h"

/**
* free_str - Frees a string
* @str: String to free
* Return: void
*/

void free_str(char *str)
{
	if (str == NULL)
		return;

	free(str);
}

/**
* free_str_split - Frees memory allocated during string split
* @a: Array of strings to free
* Return: void
*/

void free_str_split(char **a)
{
	if (a == NULL)
		return;

	free(a);
}
