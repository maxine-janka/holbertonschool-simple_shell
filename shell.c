#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - Entry point
 *
 * @argc: Number of arguments (void)
 * @argv: An array of arguments
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t buff_size = 0;
	ssize_t input;
	(void)argc;
	char **str;
	int i = 0, status;
	char *token;
	pid_t child;
	int len;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
				
		input = getline(&buffer, &buff_size, stdin);
		
		if (input == -1)
		{
			free(buffer);
			exit(0);
		}
		len = strlen(buffer);
		while (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
		{
			i++;
		}
		if (i == len)
		{
			continue;
		}

		str = malloc(sizeof(char *) * 256);
		
		token = strtok(buffer, " \n\t");

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
			perror("error");
			free(str);
			exit (1);
		}

		if (child == 0)
		{
			if (execve(str[0], str, NULL) == -1)
				perror("error");
				exit (1);
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(str);
	}
	free(buffer);
	return (0);
}
