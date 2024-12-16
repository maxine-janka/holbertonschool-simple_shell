#include "shell.h"

/**
 * resolve_command - search for command in PATH
 * @command: command being searched
 * Return: found command, otherwise NULL
 */
char *resolve_command(char *command)
{
	char *path_env = getenv("PATH");
	char *path, *token, *resolved_path;
	struct stat st;

	if (path_env == NULL)
	{
		return (NULL);
	}
	path = strdup(path_env);
	if (path_env == NULL)
	{
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		resolved_path = malloc(strlen(token) + strlen(command) + 2);
		if (resolved_path == NULL)
		{
			perror("malloc fail");
			free(path);
			return (NULL);
		}

		sprintf(resolved_path, "%s/%s", token, command);
		if (stat(resolved_path, &st) == 0 && access(resolved_path, X_OK) == 0)
		{
			free(path);
			return (resolved_path);
		}
		free(resolved_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
