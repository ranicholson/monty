#ifndef MONTY_H_
#define MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*___________Helper_Functions_____________*/
char *_tokenize(char *line);
void arg_error(void);
int malloc_error(void);
void open_error(char *arg);
int invalid_opcode(char *opcode, unsigned int ln_count);
void free_stack(stack_t *head);
int op_check(char *opcode, char *num);
int monty_helper(unsigned int ln_count, char *line, stack_t **stack);
int line_helper(FILE *fd, stack_t **stack);
int str_cmp_opcode(char *opcode2);
int invalid_opcode2(char *opcode, unsigned int ln_count);

/*_____GLOBAL_VAR___________________________*/
extern int num;

/*________OP_FUNCTIONS__________*/
void (*func_select(char *opcode))(stack_t **, unsigned int);
void push_func(stack_t **stack, unsigned int ln_count);
void op_push(stack_t **head, unsigned int n);
int stack_init(stack_t **head, unsigned int n);
void op_pall(stack_t **h, unsigned int n);
void op_pint(stack_t **stack, unsigned int ln_count);
void op_pop(stack_t **stack, unsigned int ln_count);
void op_swap(stack_t **stack, unsigned int ln_count);
void op_add(stack_t **stack, unsigned int ln_count);
void op_nop(stack_t **stack, unsigned int ln_count);
void op_sub(stack_t **stack, unsigned int ln_count);
void op_div(stack_t **stack, unsigned int ln_count);
void op_mul(stack_t **stack, unsigned int ln_count);
void op_mod(stack_t **stack, unsigned int ln_count);
void op_pchar(stack_t **stack, unsigned int ln_count);
void op_rotr(stack_t **stack, unsigned int ln_count);

#endif
