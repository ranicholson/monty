#include "monty.h"
/**
 * func_select - This function looks through in array of structs
 * @opcode: This is the operation code that is passe from the main
 * Return: is 1 if successful and 0 if failed.
 */
void (*func_select(char *opcode))(stack_t **, unsigned int)
{
	int idx = 0;

	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{'\0', NULL}
	};
	while (ops[idx].opcode)
	{
		if (strcmp(opcode, ops[idx].opcode) == 0)
		{
			return (ops[idx].f);
		}
		idx++;
	}

	return (NULL);
}
