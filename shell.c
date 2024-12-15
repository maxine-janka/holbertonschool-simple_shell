#include "shell.h"

/**
 * main - Entry point to simple shell.
 *
 * Return: 0 (Success).
 */

int main(void)
{
	char *line;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			
		}
		if (_strlen(line) == 0 || white_space(line))
		{
			free(line);
			continue;
		}
		execute_command(line);
		free(line);
	}
	return (0);
}
