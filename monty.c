#include "monty.h"

/**
 * main - The entry point into the monty app.
 * @argc: The number of arguments passed in
 * @argv: The arguments passed in on the command line
 * Return: int 0 if succesful
 */
int main(int argc, char **argv)
{
	int fd, ret = 0;
	char *buffer = NULL;
	stack_l *head = NULL;

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
	printf("file descriptor %d\n", fd);
	do
	{
	}
	while (ret != -1);
	close(fd);
	return (0);
}
