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

/**
 * func_select - This function looks through in array of structs
 * @opcode: This is the operation code that is passe from the main
 * Return: is 1 if successful and 0 if failed.
 */

void (*func_select(char *opcode))(stack_t **, unsigned int)
{
	int idx = 0;

	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{'\0', NULL}
	};
	while (ops[idx].opcode)
	{
		if (strcmp(opcode, ops[idx].opcode) == 0)
		{
			return (ops[idx].f);
		}
		idx++;
	}

	return (NULL);
}
