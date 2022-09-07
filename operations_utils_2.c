#include "monty.h"

/**
 * add_op - adds the top two elements of the stack.
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */
void add_op(stack_l **stack, unsigned int line_no)
{
	stack_l *ptr;
	stack_l *first;

	if (*stack == NULL || (*stack)->next == NULL)
		command_error(line_no, *stack, "can't add, stack too short");

	ptr = *stack;
	first = *stack;
	ptr = ptr->next;
	ptr->n += first->n;
	ptr->prev = NULL;
	free(first);
	*stack = ptr;
}
