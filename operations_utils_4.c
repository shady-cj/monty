#include "monty.h"

/**
 * queue_op - Queue op changes the doubly lists format to FIFO
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */

void queue_op(stack_l __attribute__((unused)) **stack,
		unsigned int __attribute__((unused)) line_no)
{
	stack_type = 0;
}


/**
 * stack_op - Stack op changes the doubly lists format to LIFO
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */

void stack_op(stack_l __attribute__((unused)) **stack,
		unsigned int __attribute__((unused)) line_no)
{
	stack_type = 1;
}
