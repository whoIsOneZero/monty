#include "monty.h"
/**
 * my_pall - prints all the elements of the stack. dd.
 * @head: double pointer to the head of the stack.
 * @counter: line num where opcode is found. intentionally unused.
*/
void my_pall(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	(void)counter;

	ptr = *head;
	if (ptr == NULL) /*Empty stack*/
		return;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
