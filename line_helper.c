#include "monty.h"

/**
 *
 *
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
		if (strcmp(line, "\n") == 0 || line == NULL)
		{
			read = getline(&line, &bufsize, fd);
			continue;
		}
		helper1 = monty_helper(ln_count, line, stack);
		if (helper1 == -1)
		{
			read = getline(&line, &bufsize, fd);
			continue;
		}
		if (helper1 == -2)
		{
			opcode = strtok(line, "\t\n\a\b\v\f\r");
			opcode = strdup(opcode);
			free(line);
			return (invalid_opcode(opcode, ln_count));
		}
		if (helper1 == -3)
		{
			free(line);
			return (malloc_error());
		}
		read = getline(&line, &bufsize, fd);
	}
	return (0);
}
