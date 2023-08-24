#include "monty.h"


glob_t global = {NULL, NULL};
/**
 * main - main function for monty interpreter
 * @argc: nulber of args passed
 * @argv: list of args passed
 * Return: number of args
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		command_parser(argv[1]);
	}
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * command_parser - reads a file
 * @argv: list of args
 */
void command_parser(char *argv)
{
	int line_count = 0, result = 0;
	size_t bufsize = 0;
	char *args = NULL, *item = NULL;
	stack_t *stack = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			line_count++;
			args = strtok(global.line, " \n\t\r");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#')
				continue;
			item = strtok(NULL, " \n\t\r");
			result = choose_op(&stack, args, item, line_count);
			if (result == 1)
				push_error(global.fd, global.line, stack, line_count);
			else if (result == 2)
				instruction_error(global.fd, global.line, stack, args, line_count);
		}
		free(global.line);
		free_dlistint(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
/**
 * choose_op - function to get the opcode
 * @stack: a stack or queue
 * @arg: arg to be passed
 * @item: an item of opcode
 * @line_count: a line command
 */
int choose_op(stack_t **stack, char *arg, char *item, int count)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"nop", _nop},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_is_digit(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}

