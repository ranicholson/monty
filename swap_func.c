#include "monty.h"
/**
 * op_swap - Swaps top nodes of a linked list
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: is void
 */
void op_swap(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL, *current = *stack;
	(void) ln_count;

	if (head->next->next == NULL && head->prev == NULL)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		tmp = head->next;
		tmp->prev = NULL;
		current->next = tmp->next;
		current->prev = tmp;
		tmp->next = current;
		*stack = tmp;
	}
}
