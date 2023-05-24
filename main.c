#include <signal.h>
#include "functions.h"
#include "strlib.h"
#include "getenv.h"
#include "pathlib.h"
#include "shell.h"
#include "memlib.h"

/**
* signal_handler - Handles Ctrl C signal
* @signal: Signal parameter
* Return: void
*/

void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDERR_FILENO, "\n($) ", 5);
		fflush(stdout);
	}
}

/**
* main - The main program entry
* @ac: Unused argument count
* @argv: Argument vector of strings
* @env: Environment variables
* Return: Integer - success(0), any other value
* considered an error
*/

int main(int __attribute__((unused)) ac, char **argv, char **env)
{
	char *path = NULL;
	char **paths = NULL;
	int exit_code = 0;

	path = _getenv("PATH", env);
	paths = split_str(path, ":");

	/*Listens for Ctrl C signal*/
	signal(SIGINT, signal_handler);

	/*Start the shell*/
	exit_code = shell_loop(argv[0], paths, env);

	free_str(path);
	free_str_split(paths);

	return (exit_code);
}
