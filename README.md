<div align="center">
	<img width="841" alt="Simple_Shell_Terminal_Font" src="https://github.com/user-attachments/assets/da4d0a90-def6-406d-be53-213d8b6e8db0" />
</div>

## Description
Simple shell is a custom program that replicates basic features of the UNIX shell, originally built by Ken Thompson. 
It was completed as part of a group project for Holberton School Australia.

## Requirements
- Allowed editors: vi, vim, emacs
- All code was written in <a href="https://github.com/alx-tools/Betty/wiki">Betty Style</a>
- No more than 5 functions per file

## Features
- Supports interactive and non-interactive mode
- Handles basic errors
- Custom built-in functions:
	- `env` exits the shell
	- `exit` prints the current environment
- Executes commands using the `$PATH` environment variable

## Compilation
- All files were compiled on Ubuntu 20.04 ITS gcc version 11.40
- All .c files with the shell.c file were compiled this way:
  <br />
  ```
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```

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

<b> Interactive mode</b>

When the executable file is run and the standard input is connected to a terminal, an interactive shell is invoked.
The program will display a prompt and allow the user the enter a command. To close the shell, the user can use the built-in command `exit`.
```
./hsh
$ ls
$ shell.c shell.h
$
$ exit
```
<b>Non-interactive mode</b>

If the program is invoked with the standard input not connected to a terminal, the user can use the program in non-interactive mode
```
$ echo "ls" | ./hsh
$ shell.c shell.h
$
```
<b>Output Examples</b>
| Interactive & Non Interactive Commands | Ouput |
|---------|-------|
|`ls` <br /> `echo "ls" \| ./hsh` | Lists the contents of the current directory|
|`ls -l` <br /> `echo "ls -l" \| ./hsh`  | List the contents of the current directory in long list format|
|`pwd` <br /> `echo "pwd" \| ./hsh`| Print the current working directory|
|`cat` <br /> `echo "cat" \| ./hsh` | Read the contents of a file|
|`less` <br /> `echo "less" \| ./hsh` | Displays the file contents, one screen at a time|
|`env` <br /> `echo "env" \| ./hsh` | Prints the current environment |

## Control Flow Diagram
<img width="1014" alt="Simple_shell_control_flow_diagram" src="https://github.com/user-attachments/assets/9124f92f-9399-444c-9bea-1b02c53b7dfe" />


## Authors
Crystal Carroll
<br />
Maxine Janka
