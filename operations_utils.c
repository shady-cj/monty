#include "monty.h"

/**
 * push_op - Pushes The number to the top of the stack/queue based
 * on the operation type
 * @stack: The head of the stack
 * @line_no: The line number
 * Return: void
 */
void push_op(stack_l **stack, unsigned int line_no)
{
	stack_l *ptr, *new;
	int num = atoi(command_vector[1]), error = 0;

	if (num == 0 && strcmp(command_vector[1], "0\0") != 0)
		error = 1;
	if (command_vector[1] == NULL || error)
		push_error(line_no, *stack);
	new = malloc(sizeof(stack_l));
	if (new == NULL)
		malloc_error();
	new->n = num;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	if (stack_type)
	{
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		ptr = *stack;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}


/**
 * pall_op - prints all the numbers on the stack from top to
 * bottom
 * @stack: The stack
 * @line_no: The line_no
 * Return: void
 */
void pall_op(stack_l **stack, unsigned int __attribute__((unused))line_no)
{
	stack_l *ptr;

	if (*stack == NULL)
		return;
	ptr = *stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
