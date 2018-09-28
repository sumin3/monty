#ifndef __HOLBERTON_H_
#define __HOLBERTON_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct info_s
{
	char *buff;
	int buff_len;
	stack_t *stack;
	int line_number;
	char *token;
	FILE *fd;
} info_t;
extern info_t *info;
void init_info();
void free_info();

int file_helper(char *filename);
void (*check_instruct(info_t *info))(stack_t **stack, unsigned int line_number);

/* instruction function */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);

/* helper1 function*/
int stack_len(stack_t *stack);
int is_integer(char *s);

/* helper2 function*/
stack_t *add_stack_top(stack_t **head, const int n);
stack_t *add_stack_end(stack_t **head, const int n);
void free_stack(stack_t *stack);

#endif
