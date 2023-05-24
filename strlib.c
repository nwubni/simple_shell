#include "strlib.h"

/**
* _strlen - Gets a string's length
* @str: String parameter
* Return: Number of string characters
*/

int _strlen(const char *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;

	return (count);
}

/**
* _strcmp - Compares two strings
* @str1: First string parameter
* @str2: Second string parameter
* Return: Integer
*/

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
* _strncmp - Compares two strings
* @str1: First string parameter
* @str2: Second string parameter
* @n: Number of characters to compare
* Return: Integer
*/

int _strncmp(const char *str1, const char *str2, int n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
		return (0);

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
* _strncpy - Copies one string to another
* @dest: Destination string
* @src: Source string
* @n: Number of characters to copy
* Return: void
*/

void _strncpy(char *dest, const char *src, int n)
{
	while (n > 0 && *src && (*dest++ = *src++))
		n--;
}

/**
* _strcat - Concatenates two strings
* @dest: Destination string
* @src: Source string
* Return: void
*/

void _strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;

	while ((*dest++ = *src++))
	{
	}
}
