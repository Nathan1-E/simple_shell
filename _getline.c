#include "shell.h"

/**
 * * _getline- to read from the stdin
 * * @fp: pointer to a file stream
 * * Return: the text inside the buffer
 */
char *_getline(FILE *fp)
{
	char *buffer;
	size_t size;

	buffer = NULL;
	size = 0;
	if (getline(&buffer, &size, fp) == EOF)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
