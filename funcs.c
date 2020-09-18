#include "monty.h"
/**
 * push - add new node
 * @stack: stack
 * @line_number: line_number parameter
 * Return: void
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;
	stack_t *tmp;

	new_node =  malloc(sizeof(stack_t));
	tmp = *stack;
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

new_node->n = glob_vars.glob_int;
new_node->next = *stack;
new_node->prev = NULL;

if (*stack)
{
tmp->prev = new_node;
}
*stack = new_node;

}

#include "monty.h"

/**
 * pall - prints all values on the stack or list
 * @head: pointer to the head
 * @count: line number
 */
void pall(stack_t **head, unsigned int count)
{
	stack_t *ptr = *head;

	(void)count;

	if (*head == NULL)
		return;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @head: pointer to the head
 * @count: line number
 */
void pint(stack_t **head, unsigned int count)
{
	stack_t *ptr = *head;

	if (ptr != NULL && head != NULL)
		printf("%d\n", ptr->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - removes the top element of a stack
 * @head: pointer to the head
 * @count: line number
 */
void pop(stack_t **head, unsigned int count)
{
	stack_t *tmp = *head;

	if (tmp != NULL)
	{
		tmp = *head;
		*head = tmp->next;
		tmp->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps two first elements of a list
 * @head: pointer to the head
 * @count: line number
 */
void swap(stack_t **head, unsigned int count)
{
	stack_t *ptr = *head;
	int tmp = 0;

	if (head != NULL && ptr != NULL && ptr->next != NULL)
	{
		tmp = ptr->n;
		ptr->n = ptr->next->n;
		ptr->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		free_list(head);
		exit(EXIT_FAILURE);
	}
}
