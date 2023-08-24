#include "monty.h"
/**
 * _div - division func
 * @stack: stack
 * @line_count: lines count
 */
void _div(stack_t **stack, unsigned int line_count)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n / curerent->n;
	curerent->next->n = div;
	_pop(stack, line_count);

}

/**
 * _mul - multiplies the second with the first element (from top)
 * @stack: stack
 * @line_count: lines count
 */
void _mul(stack_t **stack, unsigned int line_count)
{
	stack_t *current = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;

	mul = current->next->n * current->n;
	_pop(stack, line_count);
	current->next->n = mul;
}
/**
 * _mod - computes the remainder of the division of the second elem (top)
 * @stack: stack
 * @line_count: line count
 */
void _mod(stack_t **stack, unsigned int line_count)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n % curerent->n;
	curerent->next->n = div;
	_pop(stack, line_count);
}
/**
 * _pchar - prints the char at the top of the stackand a newline.
 * @stack: stack
 * @line_count: line count
 */
void _pchar(stack_t **stack, unsigned int line_count)
{
	int number = 0;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}

	number = (*stack)->n;
	if (number < 0 || number > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	putchar(number);
	putchar(10);
}

/**
 * _pstr - prints a string
 * @stack: stack
 * @line_count: line count
 */
void _pstr(stack_t **stack, unsigned int line_count)
{
	stack_t *current = *stack;
	(void)line_count;

	while (current && current->n)
	{
		if (current->n < 32 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	putchar(10);
}

