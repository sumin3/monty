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
/**
 * _div - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int len, div = 0;
	stack_t *second = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	div = (*stack)->n / (*stack)->next->n;
	second = (*stack)->next;
	free(*stack);
	*stack = second;
	second->prev = NULL;
	second->n = div;
}
/**
 * _mul - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int len, mul = 0;
	stack_t *second = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_info();
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->next->n * (*stack)->n;
	second = (*stack)->next;
	free(*stack);
	*stack = second;
	second->prev = NULL;
	second->n = mul;
}
