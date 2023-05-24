#include "functions.h"
#include "memlib.h"
#include "strlib.h"

/**
* int_to_str - Converts integer to string
* @val: Value to convert
* Return: String
*/

char *int_to_str(int val)
{
	int num_digits = 1;
	int temp = val;
	char *num = NULL;

	while (temp /= 10)
		num_digits++;

	num = malloc((num_digits + 1) * sizeof(char));

	if (!num)
		return (NULL);

	num[num_digits] = '\0';

	while (num_digits--)
	{
		num[num_digits] = (val % 10) + '0';
		val /= 10;
	}

	return (num);
}

/**
* count_strings - Counts group of characters in str
* @str: String parameter
* @delimiters: Split delimiters
* Return: Integer
*/

int count_strings(char *str, char *delimiters)
{
	char *str_copy = NULL;
	char *token = NULL;
	unsigned int count = 0;

	if (str == NULL || delimiters == NULL)
		return (0);

	str_copy = malloc(_strlen(str) + 1);

	if (str_copy == NULL)
		return (0);

	strcpy(str_copy, str);

	token = strtok(str_copy, delimiters);

	while (token)
	{
		count++;
		token = strtok(NULL, delimiters);
	}

	free(str_copy);
	str_copy = NULL;

	return (count);
}

/**
* split_str - Splits string in to parameters using strtok
* @str: String parameter
* @delimiters: Split delimiters
* Return: Pointer to array of strings
*/

char **split_str(char *str, char *delimiters)
{
	char *token = NULL;
	char **tokens = NULL;
	int num_words, str_len, i = 0;

	if (str == NULL)
		return (NULL);

	str_len = _strlen(str);

	token = malloc((str_len + 1) * sizeof(char));

	if (token == NULL)
		return (NULL);

	_strncpy(token, str, str_len);
	token[str_len] = '\0';

	num_words = count_strings(token, delimiters);
	free(token);

	if (num_words == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (num_words + 1));

	if (!tokens)
		return (NULL);

	str = strtok(str, delimiters);

	while (str)
	{
		tokens[i++] = str;
		str = strtok(NULL, delimiters);
	}

	tokens[i] = NULL;

	return (tokens);

}
