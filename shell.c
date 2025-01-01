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
	char *command_path = NULL;

	command_path = get_path(str[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", "./hsh", str[0]);
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
	size_t i = 0;

	if (str == NULL)
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
	int check_builtin, exit_status = 0;

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
		check_builtin = get_builtin(str, environ, &exit_status);
		if (check_builtin == 1)
		{
			continue;
		}
		if (!resolve_command_path(str))
		{
			exit_status = 127;
			free_str_array(str);
			continue;
		}
		exit_status = child_process(str, environ);
		if (exit_status != 0)
		{
			fprintf(stderr, "Execution error");

		}
		free_str_array(str);
	}
	return (0);
}
