*This project has been created as part of the 42 curriculum by spaccaud* 

### 42_get_next_line

### Description

**get_next_line** is a project at 42 school that challenges students to write a function that reads a single line from a file descriptor (fd) at a time. The function returns the line that was read, including the newline character \n if it is present. 

Repeated calls to get_next_line() allow a program to read an entire text file sequentially without losing track of the reading position. This project introduces the critical concept of **static variables** in C, handling memory management dynamically, and dealing with varying file buffer sizes. 

### Instructions

### Compilation Requirements

Your function can compile with the flag -D BUFFER_SIZE=n, which defines the buffer size for the read() system call. By default the value is 42.

bash

You can use this main :
```
int	main(void)
 	{
 	 int	fd;
 	 int	fd_2;
 	 char	*result;
 	 char	*result_2;

 	 fd = open("test.txt", O_RDONLY);
 	 fd_2 = open("test2.txt", O_RDONLY);

 	printf(" %s", get_next_line(-2));
 	 result = get_next_line(fd);
 	 result_2 = get_next_line(fd_2);

 	 while (result || result_2)
 	 {
 	 	if (result)
 	 	{
 	 		printf("%s", result);
 	 		free(result);
 	 		result = get_next_line(fd);
 	 	}
 	 	if (result_2)
 	 	{
 	 		printf("%s", result_2);
 	 		free(result_2);
 	 		result_2 = get_next_line(fd_2);
 	 	}
 	 }
 	 close(fd);
 	 close(fd_2);

 	 close(fd);
 	 return (0);
 }
```
And execute it with :

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c

### resource

I mainly use my friends to help me understand how to do things.

#### IA use

IA help me write the readme, and help understand some malloc leak or issue.