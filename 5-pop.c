#include "monty.h"
/**
 * my_pop - prints the top
 * @top: double pointer to the head of the stack
 * @line_num: the line number where opcode is
*/
void my_pop(stack_t **top, unsigned int line_num)
{
	stack_t *ptr;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(context.file);
		free(context.content);
		my_free_stack(*top);
		exit(EXIT_FAILURE);
	}

	ptr = *top;
	*top = ptr->next;
	free(ptr);
}
