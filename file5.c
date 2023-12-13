#include "monty.h"

/**
 * char_print - Prints the Ascii value.
 * @stack: pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void char_print(stack_t **stack, unsigned int number_l)
{
	int p_ascii;

	if (stack == NULL || *stack == NULL)
		string_errors(11, number_l);

	p_ascii = (*stack)->n;
	if (p_ascii < 0 ||p_ascii > 127)
		string_errors(10, number_l);
	printf("%c\n", p_ascii);
}

/**
 * str_print - Prints a string.
 * @stack: pointing to top node of the stack.
 * @line_n: line number of of the opcode.
 */
void str_print(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	int p_ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		p_ascii = temp->n;
		if (p_ascii <= 0 || p_ascii > 127)
			break;
		printf("%c", p_ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack
 * @stack: Pointing to top node of the stack.
 * @line_n: line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates stack to the bottom.
 * @stack: Pointing to top node of the stack.
 * @ln: line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

