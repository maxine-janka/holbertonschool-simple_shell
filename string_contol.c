#include "shell.h"

/**
 * _strlen - Counts the number of characters in a string.
 *
 * @str: input string.
 *
 * Return: the length of the string.
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 * white_space - Finds the length of the string that only contains
 *               spaces or tabs.
 * @str: Input string.
 *
 * Return: 1 if string only contains whitespace.
 *         0 if contains other characters.
 */
int white_space(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
