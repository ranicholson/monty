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
	int read = 0, helper1 = 0;

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
			if (strcmp(opcode, "pint") == 0 || strcmp(opcode, "pop") == 0)
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
