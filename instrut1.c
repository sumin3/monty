#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	char *tk;
	int num;

	tk = strtok(NULL, " ");
	if (tk == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(tk);
	if (num == 0)
	{
		printf("L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
	new->n = num;
	new->prev = NULL;
	new->next = *stack;
	if (new->next != NULL)
		new->next->prev = new;
	*stack = new;
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	(void) line_number;

	while(cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}

void _pint(stack_t **stack, unsigned int line_number)
{
        (void) line_number;

	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
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
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp3 = NULL, *tmp1 = *stack, *tmp2 = *stack;
	int len;

	len = stack_len(*stack);
	if (len < 2)
	{
		printf("L%u: can't swap, stack too short", line_number);
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
void _add(stack_t **stack, unsigned int line_number)
{
	int len, sum = 0;
	stack_t *new = *stack, *node3 = NULL;

        len = stack_len(*stack);
        if (len < 2)
        {
                printf("L%u: can't add, stack too short", line_number);
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
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}