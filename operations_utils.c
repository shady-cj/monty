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
	int num, error = 0;

	if (command_vector[1] == NULL || check_char(command_vector[1]) == 1)
		error = 1;
	if (error)
		command_error(line_no, *stack, "usage: push integer");
	num = atoi(command_vector[1]);
	new = malloc(sizeof(stack_l));
	if (new == NULL)
		malloc_error(*stack);
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


/**
 * pint_op - prints the value at the top of the stack, followed by
 * a new line.
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */
void pint_op(stack_l **stack, unsigned int line_no)
{
	if (*stack == NULL)
		command_error(line_no, *stack, "can't pint, stack empty");
	printf("%d\n", (*stack)->n);
}


/**
 * pop_op - removes the top element of the stack.
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */
void pop_op(stack_l **stack, unsigned int line_no)
{
	stack_l *ptr = NULL;

	if (*stack == NULL)
		command_error(line_no, *stack, "can't pop an empty stack");
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
	ptr = NULL;
	if (*stack != NULL)
		(*stack)->prev = NULL;
}


/**
 * swap_op - swaps the top two elements of the stack.
 * @stack: The stack
 * @line_no: The line number
 * Return: void
 */


void swap_op(stack_l **stack, unsigned int line_no)
{
	stack_l *ptr = NULL;
	stack_l *first = NULL;
	stack_l *second = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		command_error(line_no, *stack, "can't swap, stack too short");
	ptr = *stack;
	first = ptr;
	second = ptr->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}
