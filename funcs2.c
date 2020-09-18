#include "monty.h"

void free_list(stack_t **head)
{
	stack_t *ptr = *head;

	if (head == NULL)
		return;
	while (*head)
	{
		ptr = (*head)->next;
		free(*head);
		*head = ptr;
	}
}

/**
 * free_l - free a double linked list
 * @head: head of the linked list
 * Return: Void
 */

void free_l(stack_t *head)
{
	stack_t *aux;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}

/**
 * _isnumber - checks if the push command has a number
 * @chk_strings: character to be checked
 * Return: 0 on fail, 1 success
 */

int _isnumber(char *chk_strings)
{
	if (!chk_strings)
		return (0);

	if (*chk_strings == 45)
		chk_strings++;
	while (*chk_strings != '\0')
	{
		if (!isdigit(*chk_strings))
			return (0);
		chk_strings++;
	}
	return (1);
}

/**
 * nop - doesn't do anything
 * @stack: pointer to the stack
 * @line_number: number
 * Return: nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 *add - sum number
 *@stack:top of the stack
 *@line_number: thenumber of the command
 *Return: void
 */

/**
 * add - adds two first elements of a list
 * @head: pointer to the head
 * @count: line number
 */
void add(stack_t **head, unsigned int count)
{
	stack_t *ptr = *head;
	int num = 0;

	if (head != NULL && ptr != NULL && ptr->next != NULL)
	{
		num = ptr->n + ptr->next->n;
		pop(head, count);
		(*head)->n = num;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		free_list(head);
		exit(EXIT_FAILURE);
	}
}
