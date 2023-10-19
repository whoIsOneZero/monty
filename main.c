#include "monty.h"
bus_t context = {NULL, NULL, NULL, 0}; /*Initialization*/

/**
* main - program entry point for the Monty code interpreter
* @argc: num of arguments passed
* @argv: argument vector
* Return: [SUCCESS]: 0
*/
int main(int argc, char *argv[])
{
	char *line_code; /*current line of Monty code from the file*/
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1; /*check whether there are more lines*/
	stack_t *stack = NULL;
	unsigned int line_num = 0; /*Keep track of line number*/

	if (argc != 2) /*Program not called correctly*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); /*Open file in read mode*/
	context.file = file;
	if (!file) /*Failed to open file*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_code = NULL;
		read_line = getline(&line_code, &size, file);
		context.line_code = line_code;
		line_num++;
		if (read_line > 0) /*Read valid line of Monty code from file*/
		{
			_execute(line_code, &stack, line_num, file);
		}
		free(line_code);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
