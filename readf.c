#include "monty.h"

/**
 *operation - make the proces of the file
 *@arv_1: name of the file
 *Return: end of the proccess
 */

int operation(char *arv_1)
{
	size_t len = 0;
	unsigned int line_number = 1;
	char *line = NULL;
	char **op;
	FILE *nf;
	stack_t *head = NULL;


	nf = fopen(arv_1, "r");

	if (nf == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv_1);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, nf) != -1)
	{

		op = _splitline(line);

		if (op)
		{
			wrapper(line_number, op, &head);
		}

		free(op);
		line_number++;

	}

	free(line);
	free_l(head);
	fclose(nf);
	return (EXIT_SUCCESS);
}
