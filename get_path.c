#include "shell.h"

/**
 * get_path - search for command in directories in PATH
 * @cmd: command searched for
 * Return: full path, otherwise NULL
 */
char *get_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);

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
