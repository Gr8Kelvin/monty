#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry
 * @argumc: arguments number
 * @argumv: arguments list
 * Return: always 0
 */

int main(int argumc, char *argumv[])
{
	if (argumc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_opens(argumv[1]);
	node_free();
	return (0);
}

/**
 * nodes_create - Creates node.
 * @num: Number in node.
 * Return:1 sucess. Otherwise NULL.
 */
stack_t *nodes_create(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors_code(4);
	node->n = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/**
 * node_free - Frees nodes.
 */
void node_free(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * queue_add - Adds node to queue.
 * @n_node: Pointer to new node.
 * @line_n: line number of the opcode.
 */
void queue_add(stack_t **n_node, __attribute__((unused))unsigned int line_n)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *n_node;
	(*n_node)->prev = temp;

}

