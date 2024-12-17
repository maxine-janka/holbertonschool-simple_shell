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
	char *path_cmd = str[0];

	if (path_cmd[0] != '/')
	{
		path_cmd = get_path(str[0]);
		if (path_cmd == NULL)
		{
			perror("Command not found");
			free(str);
			exit(EXIT_FAILURE);
		}
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
		if (execve(path_cmd, str, environ) == -1)
		{
			perror("Error executing command");
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
