#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>


void sighand(int signum);


extern char **environ;
char **split(char *line, char *filename);
void exec(char **array);
void rline(char **line, int);

char *_getenv(char *name);
int _check(char *file);
void printpath(char *str);

int checkbuilt(char **args);

void shell_exit(char **args);
void shell_help(char **args);
void shell_cd(char **args);
void shell_wich(char **args);
void shell_env(char **args);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
unsigned int count_tokens(char *line, char *sep);
char *_strdup(char *str);

/**
* struct builtin - defines a struct builtin
* @command: the command given from stdin
* @func: a pointer to the function of the command
*/
typedef struct builtin
{
	char *command;
	void (*func)(char **args);
} builtins;

/**
* struct list - defines a struct list for PATH
* @str: the directory in the PATH variable
* @next: a pointer to the next node
*/
typedef struct list
{
	char *str;
	struct list *next;
} path;

path *listpath(void);
path *add_node_end(path *tail, char *tok);
void free_list(path *head);

#endif
