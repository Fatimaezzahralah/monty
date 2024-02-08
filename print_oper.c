#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack (ascii).
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pchar(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int x;
	(void)line_number;

	for (x = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 x++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}
