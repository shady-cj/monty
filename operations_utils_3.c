#include "monty.h"

/**
 * mod_op - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */
void mod_op(stack_l **stack, unsigned int line_no)
{
	stack_l *ptr;
	stack_l *first;

	if (*stack == NULL || (*stack)->next == NULL)
		command_error(line_no, *stack, "can't mod, stack too short");

	ptr = *stack;
	first = *stack;
	ptr = ptr->next;
	if (first->n == 0)
		command_error(line_no, *stack, "division by zero");
	ptr->n %= first->n;
	ptr->prev = NULL;
	free(first);
	*stack = ptr;
}
