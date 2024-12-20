#include "shell.h"

/**
 * display_prompt - Displays shell prompt in interactive mode
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * resolve_command_path - Resolves command path
 * @str: Pointer to array of command arguments
 *
 * Return: 1 if command is found and updated, otherwise 0
 */
int resolve_command_path(char **str)
{
	char *command_path;
	char *path = _getenv("PATH");

	if (!path || *path == '\0')
	{
		if (access(str[0], X_OK) == 0)
		{
			return (1);
		}
		fprintf(stderr, "Command not found: %s\n", str[0]);
		return (0);
	}
	command_path = get_path(str[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", str[0]);
		return (0);
	}
	free(str[0]);
	str[0] = command_path;
	return (1);
}

/**
 * free_str_array - frees dynamically allocated array of strings
 * @str: array of strings to free
 */
void free_str_array(char **str)
{
	int i = 0;

	if (!str)
	{
		return;
	}
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/**
 * main - Entry point to simple shell.
 *
 * Return: 0 (Success).
 */

int main(void)
{
	char *line = NULL, **str = NULL;
	int check_builtin;

	if (!_getenv("PATH"))
	{
		setenv("PATH", "/bin:/usr/bin", 1);
	}
	while (1)
	{

		display_prompt();
		line = read_line();
		if (*line == '\n')
		{
			free(line);
			continue;
		}
		str = split_string(line);
		free(line);
		if (str == NULL)
		{
			continue;
		}
		if (!resolve_command_path(str))
		{
			free_str_array(str);
			continue;
		}
		check_builtin = get_builtin(str, environ);
		if (check_builtin == 1)
		{
			free_str_array(str);
			continue;
		}
		child_process(str, environ);
		free_str_array(str);
	}
	return (0);
}
