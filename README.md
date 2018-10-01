# 0x18. C - Stacks, Queues - LIFO, FIFO
Low-level programming & Algorithm ― Data structures and Algorithms

## Goal
To create an interpreter for Monty ByteCodes files

## Purpose
- To learn what are stack and queue, and how to use them
- To learn the common implementations if stacks and queues
- To learn the most common use cases of stacks and queues
- To learn what do LIFO and FIFO
- To learn how to use global variables properly
- To learn how to work with git submodules

## Coding style
- All C files are compiled on Ubuntu 14.04 LTS and using [Betty Style](https://\github.com/holbertonschool/Betty) for checking coding and documentation styles.

## Getting started
To use, first download  this repository into your local machine by issuing the following command in your local terminal. 
```
git clone https://github.com/sumin3/monty.git
```
#### Directory
Each directoy's name includes information below
1. a number which orders projects from beginning to advanced level
2. name of programming language
3. concept/topic.
#### Change Directory
```
cd monty
```
After change current working directory to **monty** directory, issue the following command to compile

* Run .c file
```
gcc -Wall -Werror -Wextra -pedantic <filename.c> -o <output filename>
```
Once the .c files are compiled you can run the program by issuing the command
```
./<output filename> <Monty ByteCodes file>
```

## Usage Examples
```
$ ./monty 00.m
3
2
1
```
## Files
File | Function | Desc
---|---|---
monty.c | main function | execute the bytecodes.
	|  init_info function | initialize the struct, info.
	|  free_info | free the struct, info.
	|  file_helper | process a file.
        |  check_instruct | check opcode
opcode.c | _push | pushes an element to the stack.
         | _pall | prints all the values on the stack
         | _pint | prints the value at the top of the stack, followed by a new line.
         | _pop | removes the top element of the stack.
         | _swap | swap the first two element of the stack.
opcode2.c | _add | adds the top two elements of the stack.
          | _nop | do nothing
          | _sub | subtracts the top element of the stack from the second top element
          | _div | divides the second top element of the stack by the top element of the stack.
          | _mul | multiplies the second top element of the stack with the top element of the stack.
opcode3.c | _mod | computes the rest of the division of the second top element of the stack by the top element of the stack
          | _pchar | prints the char at the top of the stack, followed by a new line.
          | _pstr | prints the string starting at the top of the stack, followed by a new line.
          | _rotl | rotates the stack to the top.
          | _rotr | rotates the stack to the bottom.
## Authors
Sumin Yu