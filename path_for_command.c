#include "shell.h"

/**
 * * path_for_command- the path to excute a command
 * * @tokens: command
 * * @path: the path to be parsed
 * * Return: The command's path or NULL
 */
char *path_for_command(char *tokens, char *path)
{
	char *tmp_buffer, *tmp_buf;
	char *token;

	tmp_buf = NULL;
	token = strtok(path, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		tmp_buffer = malloc(sizeof(char) * _strlen(token) + _strlen(tokens) + 2);
		if (tmp_buffer == NULL)
		{
			errors(3);
			return (NULL);
		}
		tmp_buffer = _strcpy(tmp_buffer, token);
		tmp_buffer = _strcat(tmp_buffer, "/");
		tmp_buffer = _strcat(tmp_buffer, tokens);
		if (access(tmp_buffer, X_OK) != 0)
		{
			free(tmp_buffer);
			tmp_buffer = NULL;
			token = strtok(NULL, ":");
		}
		else
		{
			tmp_buf = malloc(sizeof(char) * _strlen(tmp_buffer) + 1);
			if (tmp_buf == NULL)
			{
				errors(3);
				return (NULL);
			}
			tmp_buf = _strcpy(tmp_buf, tmp_buffer);
			break;
		}
	}
	free(path);
	free(tmp_buffer);
	return (tmp_buf);
}
