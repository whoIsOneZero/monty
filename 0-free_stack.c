#include "monty.h"

/**
* my_free_stack - will free a doubly linked list. dd.
* @head: ptr to the head of the stack
*/
void my_free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
