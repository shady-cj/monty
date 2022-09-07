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
