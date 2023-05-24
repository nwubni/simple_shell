#include "builtin_func.h"
#include "strlib.h"
#include "print.h"

/**
* is_exit - Checks if str equals exit
* @str: Input string
* Return: Integer
*/
int is_exit(char *str)
{
	return (_strcmp(str, "exit") == 0);
}

/**
* is_env - Checks if str equals env
* @str: Input string
* @env: Environment variables
* Return: Integer
*/
int is_env(char *str, char **env)
{
	if (_strcmp(str, "env") == 0)
	{
		print_env(env);
		return (1);
	}

	return (0);
}

