#include "main.h"
#include <unistd.h>
/**
* exec - allows a process to execute another program
* @array: the line splitted into words
* ps: fork returns 0 to the child and pid to the father
* Return: -1 if execution failed, 0 if it worked
*/
int exec(char **array)
{
    pid_t _fork;
    int status, _wait;
    printf("Before execve\n");

    _fork = fork();

    /*if fork returns 0, that means the child process is running*/
    if (_fork == 0)
    {
        if (execve(array[0], array, NULL) == -1)
        {
            perror("ERROR :");
            return(-1);
        }
    }/*if fork returns negative number, that means it failed*/
    else if (_fork < 0)
    {
        printf("error in fork");
        return (-1);
    }
    else
    {
        /*wait till the child process ends*/
        _wait = wait(&status);
        if (_wait == -1)
        {
            printf("ERROR: ");
            return (-1);
        }
    }
    return (0);
}