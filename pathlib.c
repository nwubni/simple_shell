#include "pathlib.h"
#include "strlib.h"

/**
* is_path - Checks if file path is a path
* @path: File path
* Return: Integer - true(1), false(0), invalid(-1)
*/

int is_path(char *path)
{
	if (!path)
		return (-1);

	return (*path == '/');
}

/**
* file_exists - Checks if a file exists
* @path: File path
* Return: Integer - true(1), false(0)
*/

int file_exists(char *path)
{
	struct stat st;

	if (path && *path && stat(path, &st) == 0)
		return (1);

	return (0);
}

/**
* can_execute - Checks file has execution permission
* @path: File path
* Return: Integer, true(1), false(0)
*/

int can_execute(char *path)
{
	return (access(path, X_OK) == 0);
}

/**
* join_str - Joins three strings
* @str1: String 1
* @str2: String 2
* @str3: String 3
* Return: String
*/

char *join_str(char *str1, char *str2, char *str3)
{
	int l1, l2, l3, i, j;
	char *temp = NULL;

	l1 = _strlen(str1);
	l2 = _strlen(str2);
	l3 = _strlen(str3);

	temp = malloc(sizeof(char) * (l1 + l2 + l3 + 1));

	if (!temp)
		return (NULL);

	i = 0;

	for (j = 0; j < l1; j++)
		temp[i++] = str1[j];


	for (j = 0; j < l2; j++)
		temp[i++] = str2[j];

	for (j = 0; j < l3; j++)
		temp[i++] = str3[j];

	temp[i] = '\0';

	return (temp);
}

/**
* find_file - Finds a file
* @file_name: File path
* @paths: Paths to find file
* @free_mem: Indicates if return value should be freed
* Return: Integer - Found(1), Not found (0)
*/

char *find_file(char *file_name, char **paths, int *free_mem)
{
	char *file_path;
	int i = 0;

	if (!file_name)
		return (0);

	while (paths && paths[i])
	{
		file_path = join_str(paths[i], "/", file_name);


		if (file_exists(file_path))
		{
			*free_mem = 1;
			return (file_path);
		}

		free(file_path);

		i++;
	}

	return (file_name);
}
