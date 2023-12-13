#include "monty.h"

/**
 * node_mul - Adds the top two elements of the stack.
 * @stack: Pointer pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void node_mul(stack_t **stack, unsigned int number_l)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, number_l, "mul");

	(*stack) = (*stack)->next;
	summation = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = summation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_mod - mods the top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @number_l: line number of of the opcode.
 */
void node_mod(stack_t **stack, unsigned int number_l)
{
	int summation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, number_l, "mod");


	if ((*stack)->n == 0)
		more_errors(9, number_l);
	(*stack) = (*stack)->next;
	summation = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = summation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

