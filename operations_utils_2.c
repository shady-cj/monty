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

/**
 * nop_op - Doesn't do anything
 * @stack: the stack
 * @line_no: The line number
 * Return: void
 */
void nop_op(stack_l __attribute__((unused))**stack,
		unsigned int __attribute__((unused))line_no)
{
	return;
}


/**
 * sub_op - subtracts the top two elements of the stack.
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */
void sub_op(stack_l **stack, unsigned int line_no)
{
	stack_l *ptr;
	stack_l *first;

	if (*stack == NULL || (*stack)->next == NULL)
		command_error(line_no, *stack, "can't sub, stack too short");

	ptr = *stack;
	first = *stack;
	ptr = ptr->next;
	ptr->n -= first->n;
	ptr->prev = NULL;
	free(first);
	*stack = ptr;
}
