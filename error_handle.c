#include "monty.h"
/**
 * malloc_error - This function handles errors for mallocs
 * @ln_count: this is the line count that the error occured
 * @code: This is an integer that corresponds with the error
 */
int malloc_error(void)
{
        fprintf(stderr, "Error: malloc failed\n");
        return (-1);
}
/**
 * arg_error - This function is called when not enought arguments are found or no file is given
 * Return: void
 */
void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error - This function is for when a file cannot be opened.
 * Return: void
 */
void open_error(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);

}
/**
 * invalid_opcode - This function is called when an opcode does not match the struct opcode
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

	fprintf(stderr, "L%d: unknown instruction %s\n", ln_count, opcode);
	free(opcode);
	return (-1);
}
