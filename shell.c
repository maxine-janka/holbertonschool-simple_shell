#include "shell.h"

/**
 * main - Entry point to simple shell.
 *
 * Return: 0 (Success).
 */

int main(void)
{
	char *line, **str = NULL;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		line = read_line();
		if (*line == '\n')
		{
			free(line);
			continue;
		}

		str = split_string(line);
		if (str == NULL)
		{
			free(line);
			continue;
		}
		if (strcmp(str[0], "exit") == 0)
		{	
			exit (0);
		}
		if (strcmp(str[0], "env") == 0)
		{
			print_env(environ);
			continue;
		}

		child_process(str, environ);
		free(line);
	}
	return (0);
}
/**
 * print_env - Prints the current environment.
 *
 * @str: A pointer to the array from strtok with the command.
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
