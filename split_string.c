#include "shell.h"

/**
 * split_string - Splits the user innput and stores in an array.
 *
 * @line: A pointer to a string (user input).
 *
 * Return: An array of commands.
 */
char **split_string(char *line)
{
	char *token, **str;
	int i = 0;

	str = malloc(sizeof(char *) * 1024);
	if (str == NULL)
	{
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		str[i] = strdup(token);
		if (!str[i])
		{
			perror("malloc fail");
			free_str_array(str);
			return (NULL);
		}
		token = strtok(NULL, " \n\t");
		i++;
	}
	str[i] = NULL;
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
