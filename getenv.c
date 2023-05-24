#include "getenv.h"
#include "strlib.h"

/**
* _getenv - Gets an environment variable
* @name: Name of environment variable to retrieve
* @envp: Environment variables
* Return: String
*/

char *_getenv(char *name, char **envp)
{
	int n = _strlen(name), len;
	char *result = NULL;
	char **env;

	if (envp == NULL)
	return (NULL);

	for (env = envp; *env; env++)
	{
		if (_strncmp(name, *env, n) == 0)
		{
			len = _strlen(*env) - n;
			result = malloc(sizeof(char) * len);

			if (!result)
				return (NULL);

			_strncpy(result, *(env) + (n + 1), len);
			result[len -  1] = '\0';

			break;
		}
	}

	return (result);
}
