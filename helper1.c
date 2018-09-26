#include "holberton.h"
void free_stack(stack_t **stack)
{
	while (*stack)
	{
		printf("in free\n");
		free(*stack);
		*stack = (*stack)->next;
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

/**
 * _atoi - convert a string to a integer
 * @s: the string that need to convert
 * Return: return the converted integer
 */
int _atoi(char *s)
{
	int i, j, f = 0, num, minus = 1;
	unsigned int sum = 0;

	for (i = 0; s[i] != '\0' && f != 2; i++)
	{
		if (s[i] == '-')
			minus = minus * -1;
		for (j = 0; j <= 9; j++)
		{
			if (s[i] == (j + '0'))
			{
				num = j;
				sum = sum * 10 + num;
				f = 1;
			}
			else if (f == 1 && s[i] == ' ')
				f = 2;
		}
	}
	if (f == 0)
		return (0);
	return (sum * minus);

}
