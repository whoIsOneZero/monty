#include "monty.h"
/**
 * my_add - add the top two elements of the stack. dd.
 * @top: double pointer to the head of the stack. dd.
 * @line_num: line number where the opcode is.
*/
void my_add(stack_t **top, unsigned int line_num)
{
	stack_t *ptr;
	int len = 0, temp;

	ptr = *top;
	while (ptr)
	{
		ptr = ptr->next;
		len++;  /*Get num of elements in the stack*/
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(context.file);
		free(context.content);
		my_free_stack(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top;   /*Undo the change made in calculating the length*/
	temp = ptr->n + ptr->next->n;
	ptr->next->n = temp;
	*top = ptr->next;

	free(ptr);
}
