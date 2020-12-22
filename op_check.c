#include "monty.h"

/**
 * opcheck - operation to check arguments of opcodes
 * @opcode: opcode to check
 * @num: opcode value to check
 * Return: -1 upon error and 0 for success
 */

int op_check(char *opcode, char *num)
{
	int idx = 1, tmp = 0;

	if (strcmp(opcode, "push") == 0)
	{
		if (num == NULL)
			return (-1);

		if (num[0] == '-' || num[0] == '+')
		{
			while(num[idx])
			{
				tmp = isdigit(num[idx]);
				if (tmp == 0)
					return (-1);
				idx++;
			}
		}
		else if (atoi(num) == 0 && num[0] != '0')
			return (-1);
	}

	return (0);
}
