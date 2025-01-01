#include "shell.h"

/**
 * child_process - Creates a child process and executes the program.
 *
 * @str: A pointer to an array (commands).
 * @environ: Environment variables.
 *
 * Return: Nothing.
 */

int child_process(char **str, char **environ)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Error forking");
		return (1);
	}
	else if (child == 0)
	{
		if (execve(str[0], str, environ ? environ : NULL) == -1)
		{
			perror(str[0]);
			exit(127);
		}
	}
	else
	{
		if (waitpid(child, &status, 0) == -1)
		{
			perror("Wait failure");
			return (1);
		}
		if (WIFEXITED(status))
		{
			return WEXITSTATUS(status);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}
