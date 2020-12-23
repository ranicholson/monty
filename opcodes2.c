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

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		free_stack(*head);
		*head = NULL;
	}
	else
	{
		n_node->n = num;
		n_node->next = tmp;
		tmp->prev = n_node;
		n_node->prev = NULL;
		*head = n_node;
	}
}

/**
 * op_rotr - moves last element of stack to the top
 * @stack: stack to move element in
 * @ln_count: line count
 */

void op_rotr(stack_t **stack, unsigned int ln_count)
{
	stack_t *last = *stack, *tmp = NULL, *current = *stack;
	(void)ln_count;

	if (current->next == NULL || current->next->next == NULL)
		;

	else
	{
		while (last->next->next != NULL)
			last = last->next;
		current->prev = last;
		tmp = last->prev;
		tmp->next = last->next;
		last->next->prev = tmp;
		last->next = current;
		last->prev = NULL;
		*stack = last;
	}
}

/**
 * op_swap - Swaps top nodes of a linked list
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: is void
 */

void op_swap(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL, *current = *stack;
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
		tmp = head->next;
		tmp->prev = NULL;
		current->next = tmp->next;
		current->prev = tmp;
		tmp->next = current;
		*stack = tmp;
	}
}
