#include "shell.h"
#include "functions.h"
#include "builtin_func.h"
#include "execute.h"
#include "pathlib.h"
#include "memlib.h"
#include "print.h"

/**
* read_input - Reads user input
* @exit_code: Gets getline's exit status code
* Return: String
*/

char *read_input(int *exit_code)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t charactersRead;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "($) ", 4);

	charactersRead = getline(&line, &bufsize, stdin);

	if (charactersRead == -1)
	{
		free(line);
		*exit_code = -100;

		if (feof(stdin))
		{

			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);

			/*exit(EXIT_SUCCESS);*/
			return (NULL);
		}

		perror("Read line error");
		/*exit(EXIT_FAILURE);*/
		return (NULL);
	}

	if (line[charactersRead - 1] == '\n')
		line[charactersRead - 1] = '\0';

	return (line);
}

/**
* run_shell - Function that executes commands
* @params: Tokenized parameters
* @paths: User's paths
* @prog_name: The program name
* @lp: Number of times the shell ran
* @env: Environment variable
* Return: Integer
*/

int run_shell(char **params, char **paths, char *prog_name, int lp, char **env)
{
	int exit_code = 0, free_cmd = 0;

	if (is_exit(params[0]))
		return (-100);

	if (is_env(params[0], env))
		return (0);

	if (!is_path(params[0]))
		params[0] = find_file(params[0], paths, &free_cmd);

	if (file_exists(params[0]) && can_execute(params[0]))
		exit_code = _execute(params, prog_name, lp, env);
	else
	{
		err_cmd_not_found(prog_name, params[0], lp);
		exit_code = 127;
	}

	if (free_cmd)
		free_str(params[0]);

	return (exit_code);
}

/**
* shell_loop - Non interative shell mode
* @program_name: Program name
* @paths: Users path array
* @env: Environment variable
* Return: Integer
*/

int shell_loop(char *program_name, char **paths, char **env)
{
	char **params = NULL;
	char *input = NULL;
	int loop = 1;
	int exit_code = 0;

	do {
		input = read_input(&exit_code);

		if (exit_code == -100)
			break;

		params = split_str(input, " \n\r\t");

		if (params)
			exit_code = run_shell(params, paths, program_name, loop, env);

		free_str(input);
		free_str_split(params);

		loop++;
	} while (exit_code != -100);

	return (0);
}
