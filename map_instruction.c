#include "monty.h"

/**
 * map_instructions - Maps intructions to the operation functions
 * @opcode - The operation code
 * Return: The operation function
 */

void (*map_instruction(char *opcode))(stack_t **, unsigned int)
{
	int index;
	instruction_t insts[2] = {
		{"push", push_op},
		{NULL, NULL}
	};

	for (index = 0; index < 2; index++)
	{
		if (strcmp(insts[index][0], opcode) == 0)
			return (insts[index][1]);
	}
	return (NULL);
}
