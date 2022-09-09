#include "monty.h"

/**
 * check_char - Checks if any other characters other than numbers
 * is present
 * @str: The string to check
 * Return: 1 if characters found 0 if it's pure numbers
 */
int check_char(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (1);
		i++;
	}
	return (0);
}


