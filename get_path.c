#include "shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: the name of the environment variable to retrieve
 * Return: value of the environment variable, or NULL
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
		i++;
	}
	return (NULL);
}

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
 * search_in_path - search for command in PATH
 * @path: PATH directories
 * @command: command being searhed for
 * Return: file path, otherwise NULL
 */
char *search_in_path(char *path, char *command)
{
	char *path_copy, *path_token, *file_path;
	struct stat buffer;

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Memory allocation failed");
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
	return (NULL);
}

/**
 * get_path - search PATH for command
 * @command: The command
 * Return: command, otherwise NULL
 */
char *get_path(char *command)
{
	char *path;
	struct stat buffer;
	char *resolved_path;

	if (!command || *command == '\0' || stat(command, &buffer) == 0)
	{
		return (strdup(command));
	}

	path =  _getenv("PATH");

	if (!path || *path == '\0')
	{
		return (NULL);
	}
	resolved_path = search_in_path(path, command);
	if (resolved_path)
	{
		return (resolved_path);
	}
	return (NULL);
}
