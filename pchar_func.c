#include "monty.h"

/**
 * op_pchar - print char at top of the stack
 * @stack: stack to print character from
 * @ln_count: line count
 */

void op_pchar(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack;
	int count = 0;
	(void) ln_count;

	while (head != NULL)
	{
		head = head->next;
		++count;
	}

	head = *stack;

	if (count == 1)
	{
		free_stack(*stack);
		*stack = NULL;
	}

	else
	{
		if (head->n > 127 || head->n < 0)
		{
			num = 8888;
			free_stack(*stack);
			*stack = NULL;
		}

		printf("%c\n", head->n);
	}
}
