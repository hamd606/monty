#include "monty.h"
/**
 * _is_digit - checks if a digit 0 to 9
 * Return: 1 on success 0 otherwise
 * @c: input char
 **/
int _is_digit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * clean_stack - frees mallocs and closes files
 * @stack: stack to be cleaned
 */
void clean_stack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
	fclose(global.fd);
	free(global.line);
}
