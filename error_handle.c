#include "monty.h"
/**
 * malloc_error - This function handles errors for mallocs
 * Return: -1 to indicate error
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (-1);
}
/**
 * arg_error - This function is called when not enought arguments are found or
 * no file is given
 * Return: void
 */
void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error - This function is for when a file cannot be opened.
 * @arg: file name
 * Return: void
 */
void open_error(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);

}
/**
 * invalid_opcode - This function is called when an opcode does not match the
 * struct opcode
 * @opcode: This is the code that preforms a corresponding operation
 * @ln_count: this is the corresponding line that contained an invalid opcode
 * Return: Void
 */
int invalid_opcode(char *opcode, unsigned int ln_count)
{
	if (strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_count);
		free(opcode);
		return (-1);
	}
	if (strcmp(opcode, "pint") == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln_count);
		free(opcode);
		return (-1);
	}
	if (strcmp(opcode, "pop") == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_count);
		free(opcode);
		return (-1);
	}
	if (strcmp(opcode, "swap") == 0 || strcmp(opcode, "add") == 0 ||
	    strcmp(opcode, "sub") == 0)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", ln_count,
			opcode);
		free(opcode);
		return (-1);
	}
	if (strcmp(opcode, "div") == 0 || strcmp(opcode, "mod") == 0)
	{
		if (num == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", ln_count);
			free(opcode);
			return (-1);
		}
		fprintf(stderr, "L%d: can't %s, stack too short\n", ln_count, opcode);
		free(opcode);
		return (-1);
	}
	return (invalid_opcode2(opcode, ln_count));
}

/**
 * invalid_opcode2 - checking for more errors
 * @opcode: opcode to check for
 * @ln_count: line where error happened
 * Return: -1 for error
 */

int invalid_opcode2(char *opcode, unsigned int ln_count)
{
	if (strcmp(opcode, "mul") == 0)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln_count);
		free(opcode);
		return (-1);
	}
	if (opcode[0] == '#')
	{
		free(opcode);
		return (0);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln_count, opcode);
	free(opcode);
	return (-1);

}
