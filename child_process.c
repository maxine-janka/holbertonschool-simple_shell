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
		if (!environ || !*environ)
		{
			environ = NULL;
		}
		if (execve(str[0], str, environ) == -1)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Child process exit status %d\n", WEXITSTATUS(status));
		}
	}
}
