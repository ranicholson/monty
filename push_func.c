#include "monty.h"
/**
 * op_push - This adds a node to the front of the linked list
 * @head: this is a double pointer that is the head
 * @n: this is the data that needs to be inserted in the linked list
 * Return: On success return the address of the new element and NULL on failure
 */
int num;
void op_push(stack_t **head, unsigned int n)
{
	stack_t *n_node, *tmp = *head;

	if (n == 1)
	{
		tmp->n = num;
		return;
	}

	n_node = malloc(sizeof(stack_t));

	n_node->n = num;
	n_node->next = tmp;
	tmp->prev = n_node;
	n_node->prev = NULL;

	*head = n_node;
	return;
}
