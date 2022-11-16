#include "shell.h"

/**
 * * main - entry point
 * * Return: 0;
 */
int main(void)
{
	char *buffer, *command_path, *path;
	char **tokens;
	int check_for_builtin, child_status;

	while (TRUE)
	{
		printf("$ ");
		buffer = _getline(stdin);
		if (_strncmp(buffer, "\n", 1) == 0)
		{
			free(buffer);
			continue;
		}
		tokens = _parser(buffer);
		if (tokens[0] == NULL)
			continue;
		check_for_builtin = builtin_execute(tokens);
		if (check_for_builtin == 0 || check_for_builtin == -1)
		{
			free(tokens);
			free(buffer);
		}
		if (check_for_builtin == 0)
			continue;
		if (check_for_builtin == -1)
			_exit(EXIT_SUCCESS);
		path = _env_variable_finder("PATH");
		if (command_path == NULL)
		{
			printf("???\n");
			perror(tokens[0]);
			continue;
		}
		command_path = NULL;
		command_path = path_for_command(tokens[0], path);
		child_status = child(command_path, tokens);
		if (child_status == -1)
			errors(2);
	}
	free_all(tokens, buffer, command_path);
	return (-1);
}
