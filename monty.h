#ifndef MONTY_HEAD
#define MONTY_HEAD

#define  _GNU_SOURCE
#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/* ****> Stack structure <**** */
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
} stack_t;


/* **** Stack instructions <**** */
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* ****> PROGRAM CONTEXT <**** */
/**
 * struct context_s - holds relevant progam information
 * @arg: ptr to string which holds argument. dd.
 * @file: pointer to monty file
 * @content: ptr to string containing the line content
 * @lifi: flag to indicate change btn. stack & queue
 * ... whether an operation should be performed in stack-like
 * or queue-like manner
 *
 * Description: for sharing program values throughout (each file)
 */
typedef struct context_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  context_t;
extern context_t context;  /*Global variable*/

/*---> FUNCTION PROTOTYPES */
int _execute(char *, stack_t **, unsigned int, FILE *);
void my_addnode(stack_t **, int);
void my_free_stack(stack_t *);
void my_addqueue(stack_t **, int);

void my_push(stack_t **, unsigned int);
void my_pall(stack_t **, unsigned int);
void my_queue(stack_t **, unsigned int);
void my_pint(stack_t **, unsigned int);

#endif  /*MONTY_HEAD*/
