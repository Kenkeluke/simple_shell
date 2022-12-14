#ifndef MAIN_H
#define MAIN_H

#pragma endregion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * 
 * 
 * 
 * 
 */

pid_t my_ppid(void);
char *split(char *string);
char *line_reader(void);
void exec(char **args);
void shell_exit(char **args);
void shell_help(char **args);
void shell_cd(char **args);

/**
 * 
 * 
 * 
 * 
 */

typedef struct builtin
{
    char *command;
    void (*function)(char **args);
}builtins;



#endif /*MAIN_H*/
