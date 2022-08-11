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
int i;

builtins built_in[] =
{
    {"exit", shell_exit},
    {"help", shell_help},
    {"cd", shell_cd}
};

for(i = 0; i < 3; i++)
	{
		printf("%s\n", args[0]);
		if( args[0] == built_in[i].command)
		{
			built_in[i].function(args);
			printf("we did it\n");
			
		}
	}

child = fork();

if( child < 0)
{
perror("An error occurred");
}

if(child == 0)
{
	if (execve(args[0], args, NULL) == -1)
	        perror("Error");

}

else
{
wait(&wstatus);
printf("done\n");
}
}
