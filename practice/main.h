#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char** environ;
char** split(char* line, unsigned int* n_words, size_t n);
int exec(char** array);
int rline(char** line, size_t* linesize);

char* _getenv(const char* name);
int _check(char* file);
void printpath(char* str);

typedef struct list
{
	char* str;
	struct list* next;
} path;

path* listpath(path head, char* pathvalue);
path* add_node_end(path* tail, const char* tok);


#endif