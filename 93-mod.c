#include "monty.h"
/**
 * my_mod - calcs. the remainder from the division of the top two elements
 * of the stack. dd.
 * @top: double pointer to the head of the stack.
 * @line_num: line number where the opcode is.
*/
void my_mod(stack_t **top, unsigned int line_num)
{
	stack_t *ptr;
	int len = 0, temp;

	ptr = *top;
	while (ptr)
	{
		ptr = ptr->next;
		len++;  /*Get the number of elements in the stack*/
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(context.file);
		free(context.content);
		my_free_stack(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top; /*Reassignment*/
	if (ptr->n == 0)  /*Handle division by zero*/
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(context.file);
		free(context.content);
		my_free_stack(*top);
		exit(EXIT_FAILURE);
	}

	temp = ptr->next->n % ptr->n;
	ptr->next->n = temp;
	*top = ptr->next;
	free(ptr);
}
