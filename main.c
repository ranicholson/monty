#include "monty.h"
/**
 * main - This Function calls other function that help translate opcode from a file
 * @argc: this is the argument count
 * @argv: this is the argument vector with is a doubly array.
 * Return: is an integer
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t bufsize;
	ssize_t read;
	int ln_count = 1;

	FILE *fd = fopen(argv[1], "r");
	if (fd == NULL || argc > 2)
	{
		perror("USAGE: monty file");
	}
	while(getline(&line, &bufsize, fd) != -1)
	{
		ln_count++;

	}		
	fclose(fd);
	free(line);
	return (0);
}
