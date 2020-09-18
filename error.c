#include "monty.h"

/**
 * malloc_error - prints error for malloc fail to stderr
 * @head: pointer to head of list to be freed;
 */
void malloc_error(stack_t **head)
{
	fputs("Error: malloc failed\n", stderr);
	free_list(head);
	exit(EXIT_FAILURE);
}
