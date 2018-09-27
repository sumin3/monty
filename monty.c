#include "monty.h"
/**
 * main - main function
 * @ac: number of arguments
 * @av: arguments
 * Return: return 0
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_helper(av[1], stack);
	exit(EXIT_SUCCESS);
}
/**
 * file_helper - process a file
 * @filename: filename
 * @stack: pointer that points to the address of the head of stack
 * Return: return 0
 */
int file_helper(char *filename, stack_t *stack)
{
	int line_number = 1;
	size_t buff_size = 0;
	char *token = NULL, *buff = NULL;
	FILE *fd = NULL;

	if (filename == NULL)
		exit(EXIT_FAILURE);
	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	for (; getline(&buff, &buff_size, fd) != -1; line_number++)
	{
		token = strtok(buff, " \n");
		check_instruct(token, line_number)(&stack, line_number);
	}
	free_stack(stack);
	free(buff);
	stack = NULL;
	fclose(fd);
	return (0);
}
/**
 * check_instruct - check opcode
 * @token: opcode
 * @line_number: line number
 * @stack: pointer points to the address of the head of stack
 * Return: return function pointer
 */
void (*check_instruct(char *token, unsigned int line_number))(
	stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop}
	};
	int i, num_inst = 7, cmp = 0;

	for (i = 0; i < num_inst; i++)
	{
		cmp = strcmp(token, op[i].opcode);
		if (cmp == 0)
			return (op[i].f);
	}
	if (token[0] == '#')
		return (op[6].f);
	if (cmp != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
