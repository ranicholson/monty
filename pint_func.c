#include "monty.h"
/**
 * op_pint - This function just to print the item at the top of the stack
 * @stack: this is a refrence to the stack
 * @ln_count: this is line that file is currently on
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack;
	(void) ln_count;

	if (head->prev == NULL && head->next == NULL)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
		printf("%d\n", head->n);
}
