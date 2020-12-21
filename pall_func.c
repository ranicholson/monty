#include "monty.h"
/**
 * op_pall - This prints each element of the doubly linked list
 * @h: This is the head of the list.
 * Return: The number of nodes
 */
void op_pall(stack_t **h, unsigned int n)
{
    stack_t *head = *h;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
    return;
}