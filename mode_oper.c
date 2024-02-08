#include "monty.h"
/**
 * _mode -  aswitch the mode queue/stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _mode(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	if (strcmp(datax.opcode, "queue") == 0)
		datax.mode = 1;
	else if (strcmp(datax.opcode, "stack") == 0)
		datax.mode = 0;
}
