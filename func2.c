#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_count: line count
 */
void _swap(stack_t **stack, unsigned int line_count)
{
	stack_t *current = *stack;
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}
/**
 * _pop - removes the top element
 * @stack: stack
 * @line_count: line count
 */
void _pop(stack_t **stack, unsigned int line_count)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
/**
 * _add - adds two integers
 * @stack: stack
 * @line_count: line count
 */
void _add(stack_t **stack, unsigned int line_count)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	_pop(stack, line_count);
}

/**
 * _sub - subtracts the top element of the stack from the second element
 * @stack: stack
 * @line_count: lines count
 */
void _sub(stack_t **stack, unsigned int line_count)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	_pop(stack, line_count);
}

/**
 * _nop - casts a void stack
 * @stack: stack
 * @line_count: line count
 */
void _nop(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
}
