#include "monty.h"
/**
 * stack_init - This adds a node to the front of the linked list
 * @head: this is a double pointer that is the head
 * @n: this is the data that needs to be inserted in the linked list
 * Return: On success return the address of the new element and NULL on failure
 */
int stack_init(stack_t **head, unsigned int n)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (!n_node)
		return (-1);

	n_node->n = n;
	n_node->next = NULL;
	n_node->prev = NULL;

	*head = n_node;

	return (0);
}
