#include "monty.h"

/**
 * opcode_error - takes care of instructions error
 * Return: void
 */
void opcode_error(int line_no)
{
	free_buffer();
	free_cmd_v();
	fprintf(stderr, "L%d: ", line_no);
	fprintf(stderr, "unknown instruction %s\n", command_vector[0]);
	exit(EXIT_FAILURE);
}
