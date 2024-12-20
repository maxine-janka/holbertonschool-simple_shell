#include "shell.h"

/**
 * print_env - Prints the current environment.
 *
 * @environ: A pointer to the environ.
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
 * is_number - check string represents valid number
 * @str: string being checked
 * Return: 1 string valid number, else 0
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
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
		if (str[1] != NULL)
		{
			if (is_number(str[1]))
			{
				int status = atoi(str[1]);

				exit(status);
			}
			else
			{
				fprintf(stderr, "exit: %s: numeric argument required\n", str[1]);
				exit(0);
			}
		}
		else
		{
			exit(0);
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
