#include "monty.h"

/**
 * errors_code - Prints error messages
 * @err_code: The error codes
 * 1 - no file or more than one
 * 2 - file is not a file that can be opened or read.
 * 3 - file contains an invalid instruction.
 * 4 - program is unable to allocate more memory.
 * 5 - parameter passed to "push" is not an int.
 * 6 - stack it cant pint.
 * 7 - stack it cantpop.
 * 8 - stack is too short
 */
void errors_code(int err_code, ...)
{
	va_list argum;
	char *opco;
	int line_num;

	va_start(argum, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(argum, char *));
			break;
		case 3:
			line_num = va_arg(argum, int);
			opco = va_arg(argum, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opco);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argum, int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - handles errors.
 * @err_code: The error codes
 * 6 - When the stack cant pint.
 * 7 - When the stack cant pop.
 * 8 - When stack is too short
 * 9 - Division by zero.
 */
void more_errors(int err_code, ...)
{
	va_list argum;
	char *op;
	int line_num;

	va_start(argum, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(argum, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(argum, int));
			break;
		case 8:
			line_num = va_arg(argum, unsigned int);
			op = va_arg(argum, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(argum, unsigned int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - handles errors.
 * @err_code: The error codes
 * 10 - number in  node is outside ASCII bounds.
 * 11 - The stack is empty.
 */
void string_errors(int err_code, ...)
{
	va_list argum;
	int line_num;

	va_start(argum, err_code);
	line_num = va_arg(argum, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

