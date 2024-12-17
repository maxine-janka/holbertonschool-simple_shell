#include "shell.h"

/**
 * print_env - Prints the current environment.
 *
 * @str: A pointer to the array from strtok with the command.
 *
 * Return: 0;
 */
int print_env(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}

/**
 * get_builtin - Check if command is a built-in.
 *
 * @str: A pointer to an array of commands from strtok.
 * @environ: A pointer to an array that lists environment variables.
 *
 * Return: 0 on success.
 */

int get_builtin(char **str, char **environ, char *line)
{
	if (strcmp(str[0], "exit") == 0)
	{
		free(str);
		free(line);
		exit(0);
	}
	else if (strcmp(str[0], "env") == 0)
	{
		print_env(environ);
		free(str);
		return (1);
	}
	return (0);
}
