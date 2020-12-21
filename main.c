#include "monty.h"
/**
 * main - This Function calls other function that help translate opcode from a file
 * @argc: this is the argument count
 * @argv: this is the argument vector with is a doubly array.
 * Return: is an integer
 */
int num = 0;
int main(int argc, char **argv)
{
	char *line = NULL, *opcode = NULL, *tmp_num = NULL, *delim = " \t\n";
	unsigned int ln_count = 1;
	size_t bufsize;
	stack_t *stack;
	int read = 0, node_chk = 0;
	FILE *fd = NULL;
	void (*func_ptr)(stack_t **, unsigned int);

	if (argc != 2)
		arg_error();
	fd = fopen(argv[1], "r");

	if (fd == NULL)
		open_error(argv[1]);
	read = getline(&line, &bufsize, fd);
	node_chk = stack_init(&stack, 0);
	if (node_chk == -1)
	{
		free(line);
		fclose(fd);
		malloc_error();
	}
	for (; read >= 0; ln_count++)
	{
		if(strcmp(line, "\n")== 0)
		{
			read = getline(&line, &bufsize, fd);
			continue;
		}
		opcode = strtok(line, delim);
		tmp_num = strtok(NULL, delim);
/*		printf("opcode : %s || temp_num: %s\n", opcode, tmp_num);*/
		if (op_check(opcode, tmp_num) == -1)
		{
			free_stack(stack);
			opcode = strdup(opcode);
			free(line);
			fclose(fd);
			invalid_opcode(opcode, ln_count);
		}
		if (tmp_num != NULL)
			num = atoi(tmp_num);
		func_ptr = func_select(opcode);
		if (func_ptr == NULL)
		{
			opcode = strdup(opcode);
			free(line);
			fclose(fd);
			free_stack(stack);
			invalid_opcode(opcode, ln_count);
		}
		func_ptr(&stack, ln_count);
/*		printf("ln_count = [%d] ", ln_count);*/
		if (stack == NULL)
		{
			free(line);
			fclose(fd);
			malloc_error();
		}
		read = getline(&line, &bufsize, fd);
	}
	fclose(fd);
	free(line);
	free_stack(stack);
	return (0);
}
/**
 *
 *
 *
 *
 */
