#include "monty.h"
/**
 * _push - pushes an element to the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *tk;
	int num, integer;

	tk = strtok(NULL, " \n");
	integer = is_integer(tk);
	if (tk == NULL || integer == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(tk);
	add_dnodeint(stack, num);
}
/**
 * _pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	(void) line_number;

	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - removes the top element of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
		(*stack)->prev = NULL;
	}
}
/**
 * _swap - removes the top element of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp3 = NULL, *tmp1 = *stack, *tmp2 = *stack;
	int len;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp2 = (*stack)->next;
	tmp3 = tmp2->next;
	(*stack) = tmp2;
	(*stack)->prev = NULL;
	(*stack)->next = tmp1;
	tmp1->prev = *stack;
	tmp1->next = tmp3;
}
