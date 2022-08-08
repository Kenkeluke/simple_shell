#include "main.h"
/**
 *
 *
 *
 *
 *
 *
 */

void exec(char **args)
{
pid_t child;
pid_t wstatus;

child = fork();

if( child < 0)
{
perror("error");
}

if(child == 0)
{
	if (execve(args[0], args, NULL) == -1)
	        perror("error");

}

else
{
wait(&wstatus);
printf("done\n");
}
}
