#include "monty.h"

int num;

/**
 * main - calls other function that help translate opcode from a file
 * @argc: this is the argument count
 * @argv: this is the argument vector with is a doubly array.
 * Return: is an integer
 */

int main(int argc, char **argv)
{
	stack_t *stack;
	int node_chk = 0, helper = 0;
	FILE *fd = NULL;

	if (argc != 2)
		arg_error();
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		open_error(argv[1]);
	node_chk = stack_init(&stack, 0);
	if (node_chk == -1)
	{
		fclose(fd);
		malloc_error();
		exit(EXIT_FAILURE);
	}
	helper = line_helper(fd, &stack);

	if (helper == -1)
	{
		fclose(fd);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	fclose(fd);
	free_stack(stack);
	return (0);
}
/**
 * monty_helper -This is a helper function to help execute the main.
 * @ln_count: line count
 * @line: This is the line or current command
 * @stack: this is a refrence to the stack linked list
 * Return: is -1 for failure and 0 for success
 */
int monty_helper(unsigned int ln_count, char *line, stack_t **stack)
{
	char *opcode = NULL, *tmp_num = NULL,  *delim = " \t\n\a\b\v\f\r";
	void (*func_ptr)(stack_t **, unsigned int);

	opcode = strtok(line, delim);

	if (opcode == NULL)
		return (-1);
	tmp_num = strtok(NULL, delim);
	if (op_check(opcode, tmp_num) == -1)
	{
		return (-2);
	}

	if (tmp_num != NULL)
		num = atoi(tmp_num);

	func_ptr = func_select(opcode);
	if (func_ptr == NULL)
	{
		return (-2);
	}
	func_ptr(stack, ln_count);
	if (stack == NULL)
	{
		return (-3);
	}
	return (0);
}
