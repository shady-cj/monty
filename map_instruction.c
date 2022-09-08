#include "monty.h"

/**
 * map_instructions - Maps intructions to the operation functions
 * @opcode - The operation code
 * Return: The operation function
 */

void (*map_instruction(char *opcode))(stack_l **, unsigned int)
{
	int index;
	instruction_t insts[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{"stack", stack_op},
		{"queue", queue_op},
		{NULL, NULL}
	};

	for (index = 0; insts[index].opcode; index++)
	{
		if (strcmp(insts[index].opcode, opcode) == 0)
			return (insts[index].f);
	}
	return (NULL);
}
