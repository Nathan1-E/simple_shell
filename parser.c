#include "shell.h"
/**
 * * _parser- to parse the string
 * * @buffer: a string to be parsed
 * * Return: Parsed string
 */
char **_parser(char *buffer)
{
	char *token;
	char **tokens;
	unsigned int i;

	tokens = malloc(sizeof(char **) * _strlen(buffer) + 1);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, "\n ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
