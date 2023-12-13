#include "monty.h"

/**
 * stack_add - Adds a node
 * @n_node: Pointer to the new node.
 * @line_n: line number of of the opcode.
 */
void stack_add(stack_t **n_node, __attribute__((unused))unsigned int line_n)
{
	stack_t *temp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	temp = head;
	head = *n_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * stack_prints - print to the stack.
 * @stack: Pointer  pointing to top node
 * @number_l: line number of  the opcode.
 */
void stack_prints(stack_t **stack, unsigned int number_l)
{
	stack_t *temp;

	(void) number_l;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * top_pop - pop the top node
 * @stack: Pointer pointing to top node of the stack.
 * @number_l: Interger representing the line number of of the opcode.
 */
void top_pop(stack_t **stack, unsigned int number_l)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_errors(7, number_l);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * top_print - Prints the top node
 * @stack: pointing to top node of the stack.
 * @number_l: line number of the opcode.
 */
void top_print(stack_t **stack, unsigned int number_l)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, number_l);
	printf("%d\n", (*stack)->n);
}
