#include "monty.h"
info_t *info = NULL;

/**
 * main - main function
 * @ac: number of arguments
 * @av: arguments
 * Return: return 0
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_info();
	file_helper(av[1]);
	exit(EXIT_SUCCESS);
}
/**
 * init_info - initialize info
 */
void init_info(void)
{
	info = malloc(sizeof(info_t));
	if (info == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(info);
		exit(EXIT_FAILURE);
	}
	info->buff_len = 0;
	info->line_number = 1;
	info->stack = NULL;
	info->token = NULL;
	info->buff = NULL;
	info->fd = NULL;
}
/**
 * free_info - free instruct info
 */
void free_info(void)
{
	free(info->buff);
	free_stack(info->stack);
	fclose(info->fd);
	free(info);

}
/**
 * file_helper - process a file
 * @filename: filename
 * Return: return 0
 */
int file_helper(char *filename)
{
	size_t buff_size = 0;

	if (filename == NULL)
		exit(EXIT_FAILURE);
	info->fd = fopen(filename, "r");
	if (info->fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(info);
		exit(EXIT_FAILURE);
	}
	for (; getline(&(info->buff), &buff_size, info->fd) != -1;
	     info->line_number++)
	{
		info->token = strtok(info->buff, " \n");
		check_instruct(info->token, info->line_number)(
			&(info->stack), info->line_number);

	}
	free_info();
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

	if (token == NULL)
		return (_nop);
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
		free_info();
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
