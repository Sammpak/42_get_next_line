*This project has been created as part of the 42 curriculum by spaccaud* 

### 42_get_next_line

### Description

**get_next_line** is a project at 42 school that challenges students to write a function that reads a single line from a file descriptor (fd) at a time. The function returns the line that was read, including the newline character \n if it is present. 

Repeated calls to get_next_line() allow a program to read an entire text file sequentially without losing track of the reading position. This project introduces the critical concept of **static variables** in C, handling memory management dynamically, and dealing with varying file buffer sizes. 

### Instructions

### Compilation Requirements

Your function can compile with the flag -D BUFFER_SIZE=n, which defines the buffer size for the read() system call. By default the value is 42.

bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c

### resource

I mainly use my friends to help me understand how to do things.

#### IA use

IA help me write the readme, and help understand some malloc leak or issue.