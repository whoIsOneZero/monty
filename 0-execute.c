#include "monty.h"
/**
* _execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: a pointer to the Monty file
* @content: content of the current line of Monty code. dd.
* Return: no return
*/
int _execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	/*Array of opcode structures*/
	instruction_t opst[] = {
				{"push", my_push},
				{"pall", my_pall},
				{NULL, NULL} /*By convention*/
				};
	unsigned int i = 0;  /*To iterate through the 'opst' array*/
	char *op;  /*Store the opcode extracted from 'content'*/

	op = strtok(content, " \n\t"); /*Tokenization*/
	if (op && op[0] == '#')  /*# for comments*/
		return (0);
	context.arg = strtok(NULL, " \n\t");  /*Store arguments if any*/
	while (opst[i].opcode && op) /*Valid opcode*/
	{
		if (strcmp(op, opst[i].opcode) == 0) /*Search for matching opcode*/
		{	opst[i].f(stack, counter); /*Call the function if there's a match*/
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)  /*NO valid opcode found*/
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	/*Line num. where unrecognized opcode was found and opcode itself*/
		fclose(file); /*Close Monty file and release resources*/
		free(content);
		my_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
