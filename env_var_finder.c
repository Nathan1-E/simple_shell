#include "shell.h"

/**
 * * _env_variable_finder- Checks the existance os env variabel
 * * @path: The variable to be chacked
 * * Return: variable or NULL if there is not env variable
 */
char *_env_variable_finder(char *path)
{
	char *copy_path, *new_path;
	unsigned int i, env_len;
	char **env_var;

	env_len = 0;
	while (environ[env_len] != NULL)
	{
		env_len++;
	}

	env_var = NULL;
	env_var = copy_env_var(env_var, env_len);

	i = 0;
	while (env_var[i] != NULL)
	{
		if (_strncmp(env_var[i], path, _strlen(path)) == 0)
		{
			copy_path = strtok(env_var[i], "=");
			copy_path = strtok(NULL, "\n\t\r ");
			if (copy_path == NULL)
			{
				errors(4);
				exit(EXIT_FAILURE);
			}

			new_path = malloc(sizeof(char) * _strlen(copy_path) + 1);
			if (new_path == NULL)
			{
				errors(3);
				return (NULL);
			}
			new_path = _strcpy(new_path, copy_path);
			free_double_pointers(env_var, env_len);
			return (new_path);
		}
		i++;
	}
	return (NULL);
}

/**
 * * copy_env_var- to copy environmetal varibales
 * * @env_var: Buffer to put the copied env variables
 * * @env_len: the length of the array of environmental varibales
 * * Return: copied environmental variable
 */
char **copy_env_var(char **env_var, unsigned int env_len)
{
	unsigned int i;

	env_var = malloc(sizeof(char **) * env_len);
	if (env_var == NULL)
	{
		errors(3);
		return (NULL);
	}

	i = 0;
	while (environ[i] != NULL)
	{
		env_var[i] = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		if (env_var[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
		env_var[i] = _strcpy(env_var[i], environ[i]);
		i++;
	}
	return (env_var);
}
