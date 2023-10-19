#include "monty.h"
/**
 * my_pint - prints value at top of the stack
 * @head: double pointer to the head of the stack.
 * @line_num: the line number where opcode is
*/
void my_pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(context.file);
		free(context.content);
		my_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
