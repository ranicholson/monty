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
 * line_helper - function to get lines from file
 * @fd: file descriptor to pull line from
 * @stack: stack
 * Return: -1 upon error or 0 if successful
 */

int line_helper(FILE *fd, stack_t **stack)
{
	char *line = NULL, *opcode = NULL;
	unsigned int ln_count = 1;
	size_t bufsize;
	int read = 0, helper1 = 0, opcode2;

	read = getline(&line, &bufsize, fd);
	for (; read >= 0; ln_count++)
	{
		helper1 = monty_helper(ln_count, line, stack);
		if (strcmp(line, "\n") == 0 || line == NULL || helper1 == -1)
		{
			read = getline(&line, &bufsize, fd);
			continue;
		}
		if (helper1 == -2)
		{
			opcode = strtok(line, " \t\n\a\b\v\f\r");
			opcode = strdup(opcode);
			free(line);
			return (invalid_opcode(opcode, ln_count));
		}
		if (helper1 == -3)
		{
			opcode = strtok(line, " \t\n\a\b\v\f\r");
			opcode2 = str_cmp_opcode(opcode);
			if (opcode2 == -1)
			{
				opcode = strdup(opcode);
				free(line);
				return (invalid_opcode(opcode, ln_count));
			}
			free(line);
			return (malloc_error());
		}
		read = getline(&line, &bufsize, fd);
	}
	free(line);
	return (0);
}

/**
 * op_check - operation to check arguments of opcodes
 * @opcode: opcode to check
 * @num: opcode value to check
 * Return: -1 upon error and 0 for success
 */

int op_check(char *opcode, char *num)
{
	int idx = 0, tmp = 0;

	if (strcmp(opcode, "push") == 0)
	{
		if (num == NULL)
			return (-1);

		if (num[0] == '-' || num[0] == '+')
			idx++;
		while (num[idx])
		{
			tmp = isdigit(num[idx]);
			if (tmp == 0)
				return (-1);
			idx++;
		}
	}
	return (0);
}

/**
 * monty_helper - This is a helper function to help execute the main.
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
	if (opcode[0] == '#')
		return (0);

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
	if (*(stack) == NULL)
	{
		return (-3);
	}
	return (0);
}

/**
 * str_cmp_opcode - This comapres to see if the command matched any
 * of the strings for error handling
 * @opcode2: this if the opcode that we are comapring
 * Return: char* with opcode that is a match
 */
int str_cmp_opcode(char *opcode2)
{
	if (strcmp(opcode2, "pint") == 0)
		return (-1);
	if (strcmp(opcode2, "pop") == 0)
		return (-1);
	if (strcmp(opcode2, "swap") == 0)
		return (-1);
	if (strcmp(opcode2, "add") == 0)
		return (-1);
	if (strcmp(opcode2, "sub") == 0)
		return (-1);
	if (strcmp(opcode2, "div") == 0)
		return (-1);
	if (strcmp(opcode2, "mul") == 0)
		return (-1);
	if (strcmp(opcode2, "mod") == 0)
		return (-1);
	if (strcmp(opcode2, "pchar") == 0)
		return (-1);
	return (0);
}
