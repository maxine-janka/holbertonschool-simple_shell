#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: 0 on success, or appropriate error code.
 */
int main(void)
{
	char *line;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
				break;
		}

		if (strlen(line) == 0 || strspn(line, " \t") == strlen(line))
		{
			free(line);
			continue;
		}

		execute_command(line);
		free(line);
	}

	return (0);
}
