#include "main.h"
#include <unistd.h>
/**
* exec - allows a process to execute another program
* @argv: the line splitted into words
* ps: fork returns 0 to the child and pid to the father
* Return: -1 if execution failed, 0 if it worked
*/
void exec(char **argv)
{
	pid_t _fork;
	int status, _wait;

	_fork = fork();
	/*if fork returns 0, that means the child process is running*/
	if (_fork == 0)
	{
		execve(argv[1], argv + 1, environ);
		perror(argv[0]);
		exit(0);
	} /*if fork returns negative number, that means it failed*/
	else if (_fork < 0)
	{
		perror(argv[0]);
	}
	else
	{
		/*wait till the child process ends*/
		_wait = wait(&status);
		if (_wait == -1)
		{
			perror(argv[0]);
		}
	}
}
