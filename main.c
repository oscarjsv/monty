#include "monty.h"

/**
 *main - run monty
 *@argc: number arguments
 *@argv: name argument
 *Return: success
 */

int main(int argc, char *argv[])
{


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	operation(argv[1]);

	return (EXIT_SUCCESS);
}
