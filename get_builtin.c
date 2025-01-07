#include "shell.h"

/**
 * print_env - Prints the current environment.
 *
 * @environ: A pointer to the array from strtok with the command.
 *
 * Return: 0;
 */
int print_env(char **environ)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
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
	if (strcmp(str[0], "exit") == 0)
	{
		if (str[1] == NULL)
		{
			free_str_array(str);
			exit(0);
		}
		else
		{
			fprintf(stderr, "./hsh: exit: too many arguments\n");
			free_str_array(str);
			return (1);
		}
	}
	else if (strcmp(str[0], "env") == 0)
	{
		print_env(environ);
		free_str_array(str);
		return (1);
	}
	return (0);
}
