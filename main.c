#include "monty.h"
/**
 * main - This Function calls other function that help translate opcode from a file
 * @argc: this is the argument count
 * @argv: this is the argument vector with is a doubly array.
 * Return: is an integer
 */

int main(int argc, char **argv)
{
	char *line = NULL, *opcode = NULL, *num = NULL;
	void (*func_ptr)(stack_t **, unsigned int);
	unsigned int ln_count = 0;
	size_t bufsize;
	stack_t *stack;
	int read = 0;

	FILE *fd = fopen(argv[1], "r");
	if (fd == NULL || argc > 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &bufsize, fd);
	while (read >= 0)
	{
		opcode = strtok(line, " ");
		num = strtok(NULL, " ");
	    func_ptr = func_select(opcode);
		func_ptr(&stack, ln_count);
		ln_count++;
		read = getline(&line, &bufsize, fd);
	}
	fclose(fd);
	free(line);
	return (0);
}
