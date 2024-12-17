#include "shell.h"

/**
 * resolve_command - Resolves the full path of a command.
 * @cmd: command to resolve.
 * Return: resolved path or NULL
 */
char *resolve_command(char *cmd)
{
	char *path_cmd;

	if (cmd[0] == '/')
	{
		path_cmd = strdup(cmd);
		return (path_cmd);
	}
	path_cmd = get_path(cmd);
	if (path_cmd == NULL)
	{
		perror("Command not found");
	}
	return (path_cmd);
}

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
	char *path_cmd;

	path_cmd = resolve_command(str[0]);
	if (path_cmd == NULL)
	{
		free(str);
		return;
	}
	child = fork();
	if (child == -1)
	{
		perror("Error forking");
		free(path_cmd);
		free(str);
		return;
	}
	if (child == 0)
	{
		if (execve(path_cmd, str, environ) == -1)
		{
			perror("Error executing command");
			free(path_cmd);
			free(str);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(path_cmd);
	free(str);
}
