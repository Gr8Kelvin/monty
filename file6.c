#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int number_l)
{
	(void)stack;
	(void)number_l;
}


/**
 * node_swap - Swaps the top two elements of the stack.
 * @stack: Pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void node_swap(stack_t **stack, unsigned int number_l)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, number_l, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * node_add - Adds the top two elements of the stack.
 * @stack: Pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void node_add(stack_t **stack, unsigned int number_l)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, number_l, "add");

	(*stack) = (*stack)->next;
	summation = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_sub - subtract the top
 * @stack: Pointing to top node of the stack.
 * @number_l: Iline number of of the opcode.
 */
void node_sub(stack_t **stack, unsigned int number_l)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, number_l, "sub");


	(*stack) = (*stack)->next;
	summation = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = summation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_div - Divides the top
 * @stack: Pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void node_div(stack_t **stack, unsigned int number_l)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, number_l, "div");

	if ((*stack)->n == 0)
		more_errors(9, number_l);
	(*stack) = (*stack)->next;
	summation = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = summation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

