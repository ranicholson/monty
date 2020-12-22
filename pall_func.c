#include "monty.h"
/**
 * op_pall - This prints each element of the doubly linked list
 * @h: This is the head of the list.
 * @n: line count
 */
void op_pall(stack_t **h, unsigned int n)
{
	stack_t *head = *h;
	(void)n;

	while (head->next != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	return;
}
