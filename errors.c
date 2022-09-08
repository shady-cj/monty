#include "monty.h"

/**
 * opcode_error - takes care of instructions error
 * @line_no: Line number
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
 * command_error - handles command errors such as push, pint
 * pop, swap, add etc..
 * @line_no: The line number
 * @stack: The stack of doubly linked list
 * @message: The error message
 * Return: void
 */
void command_error(int line_no, stack_l *stack, char *message)
{
	free_stack(stack);
	free_cmd_v();
	fprintf(stderr, "L%d: %s\n", line_no, message);
	exit(EXIT_FAILURE);
}

