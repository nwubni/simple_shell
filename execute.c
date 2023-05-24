#include "execute.h"
#include "print.h"

/**
* _execute - Executes program
* @params: Parameters
* @program_name: Program name
* @loop: Shell loop count
* @env: Environment variables
* Return: void
*/

int _execute(char **params, char *program_name, int loop, char **env)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		return (0);
	}

	if (pid == 0)
	{
		if (execve(params[0], params, env) == -1)
		{
			err_cmd_not_found(program_name, params[0], loop);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);

			if (isatty(STDIN_FILENO) == 1)
				return (status);
		}
	}

	return (status);
}
