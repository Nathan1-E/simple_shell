#include "shell.h"

/**
 * *free_double_pointers- to free two dimentional array
 * * @double_pointers: a two dimensional arary to be freed
 * * @env_len: length of double pointers
 */
void free_double_pointers(char **double_pointers, unsigned int env_len)
{
	unsigned int i;

	i = 0;
	while (i < env_len)
	{
		free(double_pointers[i]);
		i++;
	}
	free(double_pointers);
}

/**
 * * free_all- to free all the memory allocated by malloc
 * * @tokens: memory having tokens
 * * @buffer: form _getline
 * * @command_path: memory having command path
 */
void free_all(char **tokens, char *buffer, char *command_path)
{
	free(tokens);
	free(buffer);
	free(command_path);
}
