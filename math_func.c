#include "monty.h"

/**
 * op_add - Addes top two elements of a linked list
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */

void op_add(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL;
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
		head->next->n  = head->n + head->next->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}

/**
 * op_div - divides top element into second element
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */

void op_div(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL;
	int count = 0;

	(void) ln_count;

	while (head != NULL)
	{
		head = head->next;
		++count;
	}
	head = *stack;
	if (count < 3 || head->n == 0)
	{
		if (count == 1)
			num = 2;
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		head->next->n  = head->next->n / head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}

/**
 * op_mod - divides top element into second element
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */

void op_mod(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL;
	int count = 0;

	(void) ln_count;

	while (head != NULL)
	{
		head = head->next;
		++count;
	}
	head = *stack;
	if (count < 3 || head->n == 0)
	{
		if (count == 1)
			num = 2;
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		head->next->n  = head->next->n % head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}

/**
 * op_mul - multiplies top element into second element
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */

void op_mul(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL;
	int count = 0;

	(void) ln_count;

	while (head != NULL)
	{
		head = head->next;
		++count;
	}
	head = *stack;
	if (count < 3 || head->n == 0)
	{
		free_stack(*stack);
		*stack = NULL;
	}
	else
	{
		head->next->n  = head->next->n * head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}

/**
 * op_sub - subtracts top element from second element
 * @stack: this is the stack reference
 * @ln_count: this is line count
 * Return: void
 */

void op_sub(stack_t **stack, unsigned int ln_count)
{
	stack_t *head = *stack, *tmp = NULL;
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
		head->next->n  = head->next->n - head->n;
		tmp = head;
		head = head->next;
		free(tmp);
		head->prev = NULL;
		*stack = head;
	}
}
