#include "shell.h"

/**
 * get_path - search for command in directories in PATH
 * @cmd: command searched for
 * Return: full path, otherwise NULL
 */
char *get_path(char *cmd)
{
	char *path;
	char *path_copy;
	char *dir;
	char *full_path;

	path = getenv("PATH");
	if (!path)
	{
		return (NULL);
	}
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Error");
		return (NULL);
	}
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
		{
			perror("Error");
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
