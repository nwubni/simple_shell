#include "print.h"
#include "strlib.h"
#include "functions.h"

/**
* err_cmd_not_found - Prints command not found error
* @program_name: Program name
* @command: Command typed
* @loop: Current shell loop count
* Return: void
*/

void err_cmd_not_found(char *program_name, char *command, int loop)
{
	char *not_found = "not found\n";
	char *separator = ": ";
	char *loop_count = int_to_str(loop);

	write(STDOUT_FILENO, program_name, _strlen(program_name));
	write(STDOUT_FILENO, separator, _strlen(separator));
	write(STDOUT_FILENO, loop_count, _strlen(loop_count));
	write(STDOUT_FILENO, separator, _strlen(separator));
	write(STDOUT_FILENO, command, _strlen(command));
	write(STDOUT_FILENO, separator, _strlen(separator));
	write(STDOUT_FILENO, not_found, _strlen(not_found));

	free(loop_count);
}

/**
* _printf - Prints string on new line
* @str: String to print
* Return: void
*/

void _printf(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

/**
* print_env - Prints systems evironment variables
* @envp: Environment variable
* Return: void
*/

void print_env(char **envp)
{
	char **env;

	for (env = envp; *env; env++)
		_printf(*env);
}
