#include "monty.h"

/**
 * queue_op - Queue op changes the doubly lists format to FIFO
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */

void queue_op(stack_l **stack, unsigned int line_no)
{
	stack_type = 0;
	(void)line_no;
	(void)stack;
}


/**
 * stack_op - Stack op changes the doubly lists format to LIFO
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */

void stack_op(stack_l **stack, unsigned int  line_no)
{
	stack_type = 1;
	(void)line_no;
	(void)stack;
}
