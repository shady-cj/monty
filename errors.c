#include "monty.h"

/**
 * opcode_error - takes care of instructions error
 * @line_no - Line number
 * @stack: The stack
 * Return: void
 */
void opcode_error(int line_no, stack_l *stack)
{
	free_stack(stack);
	fprintf(stderr, "L%d: ", line_no);
	fprintf(stderr, "unknown instruction %s\n", command_vector[0]);
	free_cmd_v();	
	exit(EXIT_FAILURE);
}

/**
 * push_error - handles push command errors
 * @line_no: The line number
 * @stack: The stack of doubly linked list
 * Return: void
 */
void push_error(int line_no, stack_l *stack)
{
	free_stack(stack);
	free_cmd_v();
	fprintf(stderr, "L%d: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - handles pint operation errors
 * @line_no: The line number
 * @stack: The top og the stack pointer
 * Return: void
 */
void pint_error(stack_l *stack, int line_no)
{
	free_stack(stack);
	free_cmd_v();
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
	exit(EXIT_FAILURE);
}
