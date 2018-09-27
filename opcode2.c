#include "monty.h"
/**
 * _add -  adds the top two elements of the stack.
 * @stack: pointer that points to the address of the head of stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int len, sum = 0;
	stack_t *new = *stack, *node3 = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	new = malloc(sizeof(stack_t));
	new->n = sum;
	node3 = (*stack)->next->next;
	free((*stack)->next);
	free(*stack);
	*stack = new;
	new->prev = NULL;
	if (node3 != NULL)
		node3->prev = new;
	new->next = node3;
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
