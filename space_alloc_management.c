#include "monty.h"
/**
 * malloc_error - is invoked when there is an error during
 * mallocing
 * Return: void
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * free_buffer - frees the main buffer and assigns null
 * Return: void
 */
void free_buffer()
{
	if (buffer == NULL)
		return;
	free(buffer);
	buffer = NULL;
}

/**
 * free_cmd_v - free command_vector and assigns null
 * Return: void
 */
void free_cmd_v()
{
	int i = 0;

	if (command_vector == NULL)
		return;
	while (command_vector[i])
	{
		free(command_vector[i]);
		command_vector[i] = NULL;
		i++;
	}
	free(command_vector);
}

/**
 * free_stack - frees the doubly linked list
 * @stack: the doubly linked list
 * Return: void
 */
void free_stack(stack_l *stack)
{
	stack_l *ptr;

	if (stack == NULL)
		return;
	ptr = stack;

	while (ptr != NULL)
	{
		stack = ptr->next;
		free(ptr);
		ptr = stack;
	}
}
