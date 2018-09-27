#include "monty.h"
/**
 * is_integer - determine a string is integer or not
 * @s: the string
 * Return: return 1 if is integer, Otherwise, return 0.
 */
int is_integer(char *s)
{
	int i = 1;
	int integer = 0;

	if (s[0] == '-')
	{
		integer = 1;
		if (s[1] == '\0')
			integer = 0;
	}
	else if (s[0] >= '0' && s[0] <= '9')
		integer = 1;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			integer = 1;
		}
		else
		{
			integer = 0;
			break;
		}
		i++;
	}
	return (integer);
}
/**
 * free_stack - free a stack
 * @stack: pointer that point to address of the head of stack
 */
void free_stack(stack_t *stack)
{
	while (stack)
	{
		free(stack);
		stack = (stack)->next;
	}
}
/**
 * stack_len - find the size of a stack
 * @stack: pointer that points to the address of the head of stack
 * Return: return the size of stack
 */
int stack_len(stack_t *stack)
{
	stack_t *cur = stack;
	int len = 0;

	while (cur)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}

