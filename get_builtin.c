#include "shell.h"

/**
 * _exit - A function that exits the shell.
 *
 * @str - A pointer to the string from strtok.
 *
 * Return: nothing.
 */
void get_exit(char **str)
{
	int exit_code = 0;

	if (str[1] == NULL)
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
	exit_code = atoi(str[1]);
	free(str);
	exit(exit_code);
}

/**
 * print_env - Prints the current environment.
 *
 * @str: A pointer to the array from strtok with the command.
 *
 * Return: 0;
 */
int print_env(__attribute((unused))char **str)
{
	int i = 0;

	if (environ == NULL)
		return (-1);

	while (environ[i] != NULL)
	{
		write (STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
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
int get_builtin(char **str, char **environ)
{
	if (str == NULL)
	{
		free(str);
		return (1);
	}
	if (strcmp(str[0], "exit") == 0)
	{
		get_exit(str);
	}
	else if (strcmp(str[0], "env") == 0)
	{
		print_env(environ);
		free(str);
		return (1);
	}
	return (0);
}

