#include "monty.h"
/**
 * my_pint - prints value at top of the stack
 * @top: double pointer to the head of the stack.
 * @line_num: the line number where opcode is
*/
void my_pint(stack_t **top, unsigned int line_num)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(context.file);
		free(context.content);
		my_free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
