#include "monty.h"

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
		while(num[idx])
		{
			tmp = isdigit(num[idx]);
			if (tmp == 0)
				return (-1);
			idx++;
		}
	}
	return (0);
}
