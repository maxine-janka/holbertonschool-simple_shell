
<div align="center">
	<img width="468" alt="Simple_Shell_Terminal_Font" src="https://github.com/user-attachments/assets/8a977e86-c273-49d0-a1cb-088f84974cf3" />
</div>

## 📝Description
Simple shell is a custom program that replicates some simple features of the UNIX shell originally built by Ken Thompson. 
It was completed as part of a group project for Holberton School Australia.

## Requirements
- Allowed editors: vi, vim, emacs
- All code was written in Betty Style.
- No more than 5 functions per file.

## Features
- Supports interactive annd non-interactive mode
- Handles basic errors
- Custom built-in functions:
	- `env` exits the shell
	- `exit`prints the current environment
- Executes commands using the `$PATH` environment variable

## Compilation
- All files were compiled on Ubuntu 20.04 ITS gcc version 11.40
- All .c files with the shell.c file were compiled this way:
  <br /><br />
  `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`

## File Contents
| File | Description |
|------|-------------|
|shell.h| Header file containing function prototypes and the global `environ` variable|
|shell.c| Main C program that contains the main program and the helper functions: `display_prompt` to display the '`$`' prompt,`resolve_command_path` to check if a command can be resolved into it's full executable path and `free_str_arr` to free dynamically allocated memory| 
|read_line.c| Reads user input for a command to execute, along with argument parameters|
|split_string.c| Counts the number of arguments and splits the string into tokens|
|get_builtin.c| Contains the functions `get_built` and `print_env` that check if a command is a built-in function: `env` or `exit` and executes the command|
|get_path.c| Contains the functions `_getenv`, `allocate_file_path`, `search_in_path` and `get_path` to handle the `PATH`.
|child_process.c| A Function that creates a child process and executes a program|

## Usage
Interactive mode:

Non-interactive mode:

## Authors
Crystal Caroll
Maxine Janka
