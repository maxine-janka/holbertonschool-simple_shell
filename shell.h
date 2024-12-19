#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

extern char **environ;

/*execute functions*/
char *read_line(void);
char **split_string(char *line);
void child_process(char **str, char **environ);
char *get_path(char *command);

/*helper functions*/
void display_prompt(void);
int resolve_command_path(char **str);
void free_str_array(char **str);
char *allocate_file_path(const char *path_token, const char *command);

/*get_built in functions*/
int get_builtin(char **str, char **env);
int print_env(char **str);

/*handle strings*/
int _strlen(char *str);

#endif
