#include "shell.h"

/**
 * child_process - Creates a child process and executes the program.
 *
 * @str: A pointer to an array (commands).
 * @environ: Environment variables.
 *
 * Return: Nothing.
 */

void child_process(char **str, char **environ)
{
	pid_t child;
	int status;

	if (access(str[0], X_OK) != 0)
	{
		char *command_path = resolve_command(str[0]);

		if (command_path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", str[0]);
			free(str);
			return;
		}
		free(str[0]);
		str[0] = command_path;
	}
	child = fork();
	if (child == -1)
	{
		perror("Error forking");
		free(str);
		return;
	}
	if (child == 0)
	{
		if (execve(str[0], str, environ) == -1)
		{
			perror("Error");
			free(str);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(str);
}
