#include "monty.h"
/**
 * func_select - This function looks through in array of structs
 * @opcode: This is the operation code that is passe from the main
 * @num: this is the number that is passed.
 * Return: is 1 if successful and 0 if failed.
 */
void (*func_select(char *opcode))(stack_t **, unsigned int)
{
	int idx = 0;
	instruction_t ops[] = {
		{"push", push_func},
		{"pall", push_func},
		{'\0', NULL}
	};
	while (ops[idx].opcode)
	{
		if (ops[idx].opcode == opcode)
		{
			return (ops[idx].f);
		}
		idx++;
	}

	return (NULL);
}
