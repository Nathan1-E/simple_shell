#include "shell.h"

/**
 * * _strlen- to find the length of a string
 * * @s: Pointer to a string to find
 * * Return: Length of a string
 */
int _strlen(const char *s)
{
	int len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * * _strcmp- Compares two strings
 * * @s: The first string to be compared
 * * @str: The second string to be compared
 * * Return: int
 */
int _strcmp(const char *s, const char *str)
{
	while (*s != '\0' || *str != '\0')
	{
		if (*s != *str)
		{
			return (*s - *str);
		}
		s++;
		str++;
	}
	return (0);
}

/**
 * * _strncmp- Compares two strings until length
 * * @s: The first string to be compared
 * * @str: The second string to be compared
 * * @length: The length the function uses to perform comparision
 */
int _strncmp(char *s, char *str, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		if (*s != *str)
		{
			return (*s - *str);
		}
		s++;
		str++;
		i++;
	}
	return (0);
}

/**
 * * strcat- Concatinates two strings
 * * @s: The first string to be concatinated
 * * @str: The second string to be concatinated
 * * Return: The concatinated string
 */
char *_strcat(char *s, char *str)
{
	unsigned int i, len;

	i = 0;
	len = _strlen(s);
	while (str[i] != '\0')
	{
		s[len + i] = str[i];
		i++;
	}
	s[len + i] = '\0';
	return (s);

}

/**
 * * _strcpy- Copies a string to another buffer
 * * @s: The new buffer
 * * @str: The old buffer
 * * Return: The new buffer;
 */
char *_strcpy(char *s, char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
