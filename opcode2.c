#include "monty.h"

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
