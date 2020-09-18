#include "monty.h"

/**
 * opc- select function to call
 * @op: getline, operator
 * @line_number: line_number parameter
 * Return: void
 */

void (*opc(char *op, unsigned int line_number))(stack_t **stack, unsigned int)
{
	unsigned int i;

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop},
		{NULL, NULL}
	};


	for (i = 0; instructions[i].opcode != NULL; i++)
		{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
		return (instructions[i].f);
		}
}

	fprintf(stderr, "L%u: unknown instrucction %s\n", line_number, op);
	free(op);
	exit(EXIT_FAILURE);
}
