#include "monty.h"
char **command_vector = NULL;
int stack_type = 1;
/**
 * main - The entry point into the monty app.
 * @argc: The number of arguments passed in
 * @argv: The arguments passed in on the command line
 * Return: int 0 if succesful
 */
int main(int argc, char **argv)
{
	int fd, ret, line_no = 0;
	char *buffer = NULL;
	stack_l *head = NULL;
	void (*f)(stack_l **st, unsigned int line_no);

	if (argc > 2 || argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	do
	{
		line_no++;
		ret = filereader(fd, &buffer);
		if (ret != -1)
		{
			if (ret == -2)
				malloc_error(head);
			buffer = strip(buffer, ret);
			if (strlen(buffer) == 0)
			{
				free_buffer(&buffer);
				continue;
			}
			if (buffer[0] == '#')
			{
				free_buffer(&buffer);
				continue;
			}
			split(&buffer, head);
			f = map_instruction(command_vector[0]);
			free_buffer(&buffer);
			if (f == NULL)
				opcode_error(line_no, head);
			f(&head, line_no);
			free_cmd_v();
		}
	} while (ret != -1);
	close(fd);
	free_stack(head);
	return (0);
}
