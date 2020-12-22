#include "monty.h"
/**
 * op_push - This adds a node to the front of the linked list
 * @head: this is a double pointer that is the head
 * @n: this is the data that needs to be inserted in the linked list
 * Return: On success return the address of the new element and NULL on failure
 */

void op_push(stack_t **head, unsigned int n)
{
	stack_t *n_node, *tmp = *head;
	(void)n;
/*	printf("n = [%d]\n", n);*/
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		free_stack(*head);
		*head = NULL;
		return;
	}
	n_node->n = num;
	n_node->next = tmp;
	tmp->prev = n_node;
	n_node->prev = NULL;

	*head = n_node;
	return;
}
