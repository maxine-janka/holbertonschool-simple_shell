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

	child = fork();
	if (child == -1)
	{
		perror("Error forking");
		return;
	}
	if (child == 0)
	{
		if (execve(str[0], str, environ ? environ : NULL) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", "./hsh", 1, str[0]);
			exit(2);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", "./hsh", 1, str[0]);
		}
	}
}
