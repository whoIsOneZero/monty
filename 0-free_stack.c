#include "monty.h"

/**
* my_free_stack - will free a doubly linked list. dd.
* @head: ptr to the head of the stack
*/
void my_free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
