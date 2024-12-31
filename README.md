 ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ 
||S |||i |||m |||p |||l |||e |||       |||S |||h |||e |||l |||l ||
||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|

## Description
Simple shell is a custom program that replicates some simple features of the UNIX shell originally built by Ken Thompson. 
It was completed as part of a group project for Holberton School Australia.

## Requirements
- Allowed editors: vi, vim, emacs
- All code was written in Betty Style.
- No more than 5 functions per file.

## Features
- Suports interactive annd non-interactive mode
- Handles basic errors
- Custom built-in functions:
	- ```env``` exits the shell
	- ```exit```prints the current environment
- Executes commands using the $PATH environment variable

## Compilation
- All files were compiled on Ubuntu 20.04 ITS gcc version 11.40
- All .c files with the shell.c file were compiled this way:
```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c```

## File Contents
| File | Description |
|------|-------------|
|shell.h| Header file containing function prototypes and the global `environ` variable|
|shell.c| Main C program that contains the main program and the helper functions: `display\_prompt`
to display the `$` prompt,`resolve\_command\_path` to check if a command can be resolved into it's full
executable path and `free\_str\_arr` to free dynamically allocated memory| 
|read_line.c| Reads user input for a command to execute, along with argument parameters|
|split_string.c| Counts the number of arguments and splits the string into tokens|
|get_builtin.c| Contains the functions `get\_built` and `print\_env` that check if a command is a built-in function: `env` or `exit` and executes the command|
|get_path.c| Contains the functions `\_getenv`, `allocate\_file\_path`, `search\_in_\path` and `get\_path` to handle the `PATH`.
|child_process.c| A Function that creates a child process and executes a program|

## Usage

## Authors
Crystal Caroll
Maxine Janka
