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
	info->queue = 0;
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
	while (getline(&(info->buff), &buff_size, info->fd) != -1)
	{
		info->token = strtok(info->buff, " \n");
		check_instruct(info)(&(info->stack), info->line_number);
		info->line_number++;
	}
	free_info();
	return (0);
}
/**
 * check_instruct - check opcode
 * @info: struct
 * Return: return function pointer
 */
void (*check_instruct(info_t *info))(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr} };
	int i, num_inst = 15, cmp = 0;

	if (info->token == NULL)
		return (_nop);
	if (strcmp(info->token, "queue") == 0)
	{
		info->queue = 1;
		return (_nop);
	}
	else if (strcmp(info->token, "stack") == 0)
	{
		info->queue = 0;
		return (_nop);
	}
	for (i = 0; i < num_inst; i++)
	{
		cmp = strcmp(info->token, op[i].opcode);
		if (cmp == 0)
			return (op[i].f);
	}
	if (info->token[0] == '#')
		return (_nop);
	if (cmp != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			info->line_number, info->token);
		free_info();
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
