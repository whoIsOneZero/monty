#include "monty.h"
/**
* _execute - calls the necessary function to execute the opcode
* @top: ptr to the head of the linked list (stack)
* @line_num: line moving through the Monty file
* @file: a pointer to the Monty file
* @content: content of the current line of Monty code. dd.
* Return: [SUCCESS] - 0. [FAILURE] - 1
*/
int _execute(char *content, stack_t **top, unsigned int line_num, FILE *file)
{
	/*Array of opcode structures*/
	instruction_t opst[] = {
				{"push", my_push},
				{"pall", my_pall},
				{"pint", my_pint},
				{"pop", my_pop},
				{"swap", my_swap},
				{"add", my_add},
				/*{"nop", my_nop},*/
				{NULL, NULL} /*By convention*/
				};
	unsigned int i = 0;  /*To iterate through the 'opst' array*/
	char *op;  /*Store the opcode extracted from 'content'*/

	op = strtok(content, " \n\t"); /*Tokenization for opcode*/
	if (op && op[0] == '#')
		return (0);  /*Ignore all comments*/
	context.arg = strtok(NULL, " \n\t");  /*Store arguments if any*/
	while (opst[i].opcode && op) /*Valid opcode*/
	{
		if (strcmp(op, opst[i].opcode) == 0) /*Search for matching opcode*/
		{	opst[i].f(top, line_num); /*Call the function if there's a match*/
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)  /*NO valid opcode found*/
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
	/*Line num. where unrecognized opcode was found and opcode itself*/
		fclose(file); /*Close Monty file and release resources*/
		free(content);
		my_free_stack(*top);
		exit(EXIT_FAILURE); }
	return (1);
}
