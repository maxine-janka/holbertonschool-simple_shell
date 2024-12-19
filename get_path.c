#include "shell.h"

/**
 * allocate_file_path - allocates and constructs file path
 * @path_token: A directory from PATH
 * @command: command to append
 * Return: the constructed file path, or NULL on failure
 */
char *allocate_file_path(const char *path_token, const char *command)
{
	char *file_path;
	int command_len = strlen(command);
	int dir_len = strlen(path_token);

	file_path = malloc(command_len + dir_len + 2);
	if (!file_path)
	{
		return (NULL);
	}
	strcpy(file_path, path_token);
	strcat(file_path, "/");
	strcat(file_path, command);
	return (file_path);
}

/**
 * get_path - search PATH for command
 * @command: The command
 * Return: command, otherwise NULL
 */
char *get_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		if (!path_copy)
		{
			return (NULL);
		}
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			file_path = allocate_file_path(path_token, command);
			if (!file_path)
			{
				free(path_copy);
				return (NULL);
			}
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			free(file_path);
			path_token = strtok(NULL, ":");
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (strdup(command));
		}
	}
	return (NULL);
}
