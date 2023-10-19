#include "monty.h"
/**
 * my_push - processes the "push" opcode; adds a node to the stack
 * @head: double pointer to the head of the stack
 * @counter: the line number where the opcode is
*/
void my_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, is_digit = 0;

	if (context.arg) /*argument for the "push" opcode exists*/
	{
		if (context.arg[0] == '-')
			j++;   /*Skip minus sign*/
		for (; context.arg[j] != '\0'; j++)
		{
			if (context.arg[j] > 57 || context.arg[j] < 48)
				is_digit = 1; /*arg not a valid integer*/
		}
		if (is_digit == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(context.file);
			free(context.content);
			my_free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else  /*invalid argument for "push"*/
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(context.file);
		free(context.content);
		my_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(context.arg);  /*Convert string arg to integer*/
	if (context.lifi == 0)  /*Stack operation*/
		my_addnode(head, n);
	else					/*Queue operation*/
		my_addqueue(head, n);
}
