#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: Pointer to the dynamically allocated input string, or NULL on EOF.
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

	if (buffer[bytes_read - 1] == '\n')
		buffer[bytes_read - 1] = '\0';

	return (buffer);
}
