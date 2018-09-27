#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int len, mod = 0;
	stack_t *second = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->n % (*stack)->next->n;
	second = (*stack)->next;
	free(*stack);
	*stack = second;
	second->prev = NULL;
	second->n = mod;
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
