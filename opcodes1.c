#include "monty.h"

/**
 * op_nop - This is the function does nothing
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */

void op_nop(stack_t **stack, unsigned int ln_count)
{
	(void) stack;
	(void) ln_count;
}

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
}

/**
 * op_pchar - print char at top of the stack
 * @stack: stack to print character from
 * @ln_count: line count
 */

void op_pchar(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack;
	int count = 0;
	(void) ln_count;

	while (head != NULL)
	{
		head = head->next;
		++count;
	}

	head = *stack;

	if (count == 1)
	{
		free_stack(*stack);
		*stack = NULL;
	}

	else
	{
		if (head->n > 127 || head->n <= 0)
		{
			num = 8888;
			free_stack(*stack);
			*stack = NULL;
		}

		printf("%c\n", head->n);
	}
}

/**
 * op_pint - This function just to print the item at the top of the stack
 * @stack: this is a refrence to the stack
 * @ln_count: this is line that file is currently on
 * Return: void
 */

void op_pint(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack;
	(void) ln_count;

	if (head->prev == NULL && head->next == NULL)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
		printf("%d\n", head->n);
}

/**
 * op_pop - This function pops the first element off the list
 * @stack: this is a refernce to the stack
 * @ln_count: this is the line count
 * Return: void
 */

void op_pop(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = *stack;
	(void) ln_count;

	if (head->next == NULL && head->prev == NULL)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
		free(tmp);
		*stack = head;
	}
}

