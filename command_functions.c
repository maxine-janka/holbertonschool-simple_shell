#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: Pointer to the input string, or NULL on EOF.
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;

	bytes_read = getline(&buffer, &buffer_size, stdin);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read - 1] = '\0';
	return (buffer);
}

/**
 * execute_command - Executes a command using execve.
 *
 * @line: A pointer to a string.
 *
 * Return: Nothing.
 */
void execute_command(char *line)
{
	char *token;
	int i = 0, status;
	pid_t child;
	char **str;

	str = malloc(sizeof(char *) * 256);
	if (str == NULL)
	{
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		str[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	str[i] = NULL;

	child = fork();
	if (child == -1)
	{
		perror("Error forking");
		free(str);
		return;
	}
	if (child == 0)
	{
		if (execve(str[0], str, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(str);
	}
}
