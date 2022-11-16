#ifndef HOLBERTON_H
#define HOLBERTON_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define PROMPT "$ "
#define TRUE 1

/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * * struct list_s - linked list of variables
 * * @value: value
 * * @next: pointer to next node
 * *
 * * Description: generic linked list struct for variables.
 */
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * * struct built_s - linked list of builtins
 * * @name: name of builtin
 * * @p: pointer to function
 * *
 * * Description: struct for builtin functions.
 */
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *_getline(FILE *fp);
char **_parser(char *buffer);
char *_env_variable_finder(char *path);
char **copy_env_var(char **env_var, unsigned int env_len);
int child(char *fullpath, char **tokens);
char *path_for_command(char *tokens, char *path);
char *command_path(char *command, char *fullpath, char *path);
int executing_command(char *fullpath, char **tokens);
void errors(int error);

/* utility functions */
void _puts(char *str);
int _strlen(const char *s);
int _strcmp(const char *s, const char *str);
int _strncmp(char *s, char *str, unsigned int length);
char *_strcat(char *s, char *str);
char *_strcpy(char *s, char *str);

/* prototypes for builtins */
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

/* prototypes for the helper functions for path linked list */
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

/* prototypes for free functions */
void free_all(char **tokens, char *buffer, char *command_path);
void free_double_pointers(char **double_pointers, unsigned int env_len);
#endif /* HOLBERTON_H */

