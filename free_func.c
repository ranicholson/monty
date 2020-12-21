#include "monty.h"
/**
 * free_stack - This frees the list from a doubly linked list
 * @head: this it the head of the linked list
 * Return: is void so no return;
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
