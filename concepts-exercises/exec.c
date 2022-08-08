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
	exec(args);
	perror("error");
	exit(1);

}

else
{
wait(&wstatus);
}



}
