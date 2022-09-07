#include "monty.h"
/**
 * filereader - Reads the commands from the file
 * @fd: The file descriptor to read from
 * @buffer: The buffer to write into
 * Return: int - The size of the data written
 */

int filereader(int fd, char **buffer)
{
	char *str = NULL;
	char c;
	int i = 0, ret;

	str = malloc(sizeof(char) * 100);
	if (str == NULL)
		return (-2);
	do
	{
		ret = read(fd, &c, 1);
		if (ret == -1 || (i == 0 && ret == 0))
		{
			free(str);
			return (-1);
		}
		if (c == '\n' || ret == 0)
			continue;
		str[i] = c;
		i++;
	} while (c != '\n');
	str[i] = '\0';
	*buffer = str;
	return (i);
}
