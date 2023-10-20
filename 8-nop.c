#include "monty.h"
/**
  *my_nop- does nothing
  *@top: double ptr to the head of the stack
  *@line_num: line number where opcode is
 */
void my_nop(stack_t **top, unsigned int line_num)
{
	(void) line_num; /*Intentionally unused*/
	(void) top;
}
