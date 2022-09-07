#include "monty.h"

/**
 * strip - This helper function takes a string and removes all whitespace
 * padding from the beginning and from the end
 * @buffer: The string to strip
 * @size: The length of the string to strip
 * Return: This return back the same string with the space already
 * stripped off
 */
char *strip(char *buffer, int size)
{
	int i = size - 1, j, k;

	if (size == 0)
		return (buffer);
	while (buffer[i] == ' ' && i > 0)
	{
		buffer[i] = '\0';
		i--;
	}
	j = 0;
	while (buffer[j] == ' ' && j < size)
		j++;

	if (j != 0)
	{
		k = 0;
		while (buffer[j])
		{
			buffer[k] = buffer[j];
			buffer[j] = '\0';
			k++;
			j++;
		}
		i = k - 1;
	}
	buffer[++i] = '\0';
	return (buffer);
}

/**
 * split - splits command strings into arrays of commands
 * @buffer: The buffer to split
 * Return: void
 */

void split(char **buffer, stack_l *stack)
{
	char *s = *buffer;
	int buf_i = 3, buf_j = 100, i = 0, j = 0, found = 0;
	char d = ' ';

	command_vector = malloc(sizeof(char *) * buf_i);
	if (command_vector == NULL)
	{
		free_buffer(buffer);
		malloc_error(stack);
	}
	command_vector[i] = malloc(sizeof(char) * buf_j);
	if (command_vector[i] == NULL)
	{
		free_buffer(buffer);
		malloc_error(stack);
	}
	while (*s && (i < 2))
	{
		if (*s == d)
		{
			if (!found)
			{
				command_vector[i][j] = '\0';
				i++;
				if (i == 2)
					continue;
				command_vector[i] = malloc(sizeof(char) * buf_j);
				if (command_vector[i] == NULL)
				{
					free_buffer(buffer);
					malloc_error(stack);
				}
				j = 0;
				found = 1;
			}
		}
		else
		{
			command_vector[i][j] = *s;
			j++;
			found = 0;
		}
		s++;
	}
	if (i == 2)
		command_vector[i] = NULL;
	else
	{
	 	command_vector[i][j] = '\0';
		while (i < 2)
			command_vector[++i] = NULL;
	}
}
