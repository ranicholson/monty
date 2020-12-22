#include "monty.h"
/**
 * op_sub - subtracts top element from second element
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL;
	int count = 0;

	(void) ln_count;

	while (head != NULL)
	{
		head = head->next;
		++count;
	}
	head = *stack;
	if (count < 3)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		head->next->n  = head->next->n - head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}
