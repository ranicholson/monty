#include "monty.h"
/**
 * op_pop - This function pops the first element off the list
 * @stack: this is a refernce to the stack
 * @ln_count: this is the line count
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = *stack;
	(void) ln_count;

	if (head->next == NULL && head->prev == NULL)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
		free(tmp);
		*stack = head;
	}
}
