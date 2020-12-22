#include "monty.h"

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
	return (0);
}
