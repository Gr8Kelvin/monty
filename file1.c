#include "monty.h"

/**
 * file_open - opens a file
 * @f_name: the file name
 * Return: void
 */

void file_opens(char *f_name)
{
	FILE *file_d = fopen(f_name, "r");

	if (f_name == NULL || file_d == NULL)
		errors_code(2, f_name);

	read_file(file_d);
	fclose(file_d);
}


/**
 * read_file - reads file
 * @file_d: pointer that points to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int number_l, fmt = 0;
	char *buff = NULL;
	size_t len = 0;

	for (number_l = 1; getline(&buff, &len, fd) != -1; number_l++)
	{
		fmt = token(buff, number_l, fmt);
	}
	free(buff);
}


/**
 * token - tokenizes each line
 * @buff: line from the file
 * @number_l: line number
 * @fmt:  storage fmt.
 * Return: Returns 0. 1 if queue.
 */

int token(char *buff, int number_l, int fmt)
{
	char *opcode, *val;
	const char *delimet = "\n ";

	if (buff == NULL)
		errors_code(4);

	opcode = strtok(buff, delimet);
	if (opcode == NULL)
		return (fmt);
	val = strtok(NULL, delimet);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	funct_find(opcode, val, number_l, fmt);
	return (fmt);
}

/**
 * funct_find - scan and find the function for the opcode
 * @opcode: opcode
 * @val: argument for the opcode
 * @fmt:  storage fmt.
 * @line_n: line number
 * Return: void
 */
void funct_find(char *opcode, char *val, int line_n, int fmt)
{
	int a;
	int flag_code;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", stack_prints},
		{"pint", top_print},
		{"pop", top_pop},
		{"nop", nop},
		{"mod", node_mod},
		{"pchar", char_print},
		{"pstr", str_print},
		{"rotl", rotl},
		{"nop", nop},
                {"swap", node_swap},
                {"add", node_add},
                {"sub", node_sub},
                {"div", node_div},
                {"mul", node_mul},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag_code = 1, a = 0; func_list[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, func_list[a].opcode) == 0)
		{
			funct_call(func_list[a].f, opcode, val, line_n, fmt);
			flag_code = 0;
		}
	}
	if (flag_code == 1)
		errors_code(3, line_n, opcode);
}


/**
 * funct_call - Calls function.
 * @func: Pointer to the function
 * @op: opcode.
 * @val: numeric value.
 * @line_n: line number
 * @fmt: fmt specifier.
 */
void funct_call(funct_op func, char *op, char *val, int line_n, int fmt)
{
	stack_t *node;
	int flag_code;
	int a;

	flag_code = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag_code = -1;
		}
		if (val == NULL)
			errors_code(5, line_n);
		for (a = 0; val[a] != '\0'; a++)
		{
			if (isdigit(val[a]) == 0)
				errors_code(5, line_n);
		}
		node = nodes_create(atoi(val) * flag_code);
		if (fmt == 0)
			func(&node, line_n);
		if (fmt == 1)
			queue_add(&node, line_n);
	}
	else
		func(&head, line_n);
}

