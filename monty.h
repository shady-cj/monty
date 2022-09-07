#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

extern char **command_vector;
extern char *buffer;
extern int stack_type;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_l;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_l **stack, unsigned int line_number);
} instruction_t;

void push_op(stack_l **, unsigned int);
void malloc_error(void);
int filereader(int fd, char **buffer);
char *strip(char *buffer, int size);
void split(char *buffer);
void (*map_instruction(char *opcode))(stack_l **, unsigned int);
void pall_op(stack_l **stack, unsigned int __attribute__((unused))line_no);
void free_buffer();
void free_cmd_v();
void opcode_error(int line_no);
void free_stack(stack_l *stack);
#endif
