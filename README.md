# Montey code interpreter

This code interperates monty code that is on each line

# Monty functions

These are the montey functions and their uses in the interpreter:

## op_pop
This function removes the top element off the stack;
```bash
push 1$
push 2$
push 3$
pall$
```
Result: 
```bash
3
2
1
```
## Op_pint
This function prints the value at the top of the stack followed by a new line.
```bash
push 1
pint
push 2
pint
push 3
pint
```
Result:
```bash
3
2
1
```

## Op_Pall
This function goes through and prints the linked list from top to bottom.

## Op_push
This function adds to the linked list so the oldest item is the last out and newist is last in.

## op_sub
This Function subtracts the top two elements of a stack and combines them into one node.

## op_mul
This function Multiples the number in the top two nodes of a list. It then condenses it product down to 0;

## op_mod
This function finds the modulus of the top two numbers of a list. It then condenses it down to one node.

## op_div
This function divides the top two nodes of the list and then stores them into one node.

## op_nop
This Function does absolutely nothing. LOL

## op_add
This function adds the top two nodes of a linked list. It then stores it into one node.

## op_swap
This function swaps the top two nodes of a linked list.

# Helper_funcs

## helper_func.c
This file contains helper function that insure the initilization of the linked list, the freeing the entire linked list, and even selecting the function to return as a function pointer. 

## error_handle.c
This file handles the errors for all the function in the program. It uses returns and NULL checks to execute code to properly handle errors for the corresponsing error.
