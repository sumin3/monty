#include "monty.h"
int is_integer(char *s)
{
	int i = 0;
	int integer = 0;

	while(s[i] != '\0')
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
void free_stack(stack_t *stack)
{
	while (stack)
	{

		free(stack);
		stack = (stack)->next;
	}
}
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

