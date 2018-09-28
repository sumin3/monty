#include "monty.h"
/**
 * add_stack_end - adds a new node at the end of stack
 * @head: ponter that points to the address of head of the list
 * @n: the value of new node
 * Return:  the address of the new element, or NULL if it failed
 */
stack_t *add_stack_end(stack_t **head, const int n)
{
	stack_t *tmp = *head, *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_info();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

/**
 * add_stack_top - adds a new node at the beginning of a stack
 * @head: pointer that points the address of the head of list
 * @n: the value of the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_stack_top(stack_t **head, const int n)
{
	stack_t *new = NULL, *tmp = *head;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_info();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = tmp;
	if (tmp != NULL)
	{
		tmp->prev = new;
	}
	*head = new;
	return (new);
}
/**
 * free_stack - free a stack
 * @stack: pointer that point to address of the head of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *cur = stack;

	while (stack != NULL)
	{
		cur = cur->next;
		free(stack);
		stack = cur;
	}
	stack = NULL;
}
