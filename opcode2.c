#include "monty.h"
/**
 * _add -  adds the top two elements of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int len, sum = 0;
	stack_t *second = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	second = (*stack)->next;
	free(*stack);
	*stack = second;
	second->prev = NULL;
	second->n = sum;
}
/**
 * _nop - do nothing
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int len, sub = 0;
	stack_t *second = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	second = (*stack)->next;
	free(*stack);
	*stack = second;
	second->prev = NULL;
	second->n = sub;
}
