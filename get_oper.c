#include "monty.h"
/**
 * _push -  add a new node at the beginning
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *new, *last;
	int x = 0;

	(void)line_number;
	if (!top)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	new->n = datax.push_value;
	if (datax.mode == 0 || !*top)
	{
		if (*top)
		{
			new->next = *top;
			(*top)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*top = new;
	}
	else if (datax.mode == 1)
	{
		last = *top;
		for (x = 0; last; x++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

/**
 * _pall -  prints all the elements of a dlistint_t list
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int x;

	(void)line_number;
	for (x = 0; current; x++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}
