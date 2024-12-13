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
	int status;
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error forking");
		return;
	}
	if (child == 0)
	{
		char *args[2];

		args[0] = line;
		args[1] = NULL;

		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
