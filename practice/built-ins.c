#include "main.h"
/**
 *shell_exit - exits the shell and returns back to the original shell
 *Description : uses the exit function 
 *@args: argument lists 
 */

void shell_exit(char **args)
{
	int i;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
    exit(0);
}

/**
 *shell_help - Displays help message in shell
 *Description :Displays navigation message
 *@args: argument lists 

 */

void shell_help(char** args __attribute__((unused)))
{
    int i = 0;
    char *help_message[] = 
    {
        "Welcome to a simple shell built by Arafah and Kenkeluke\n",
        "The Following built-ins are supported:\n",
        " cd : change current working directory\n",
        " help : displays this help message\n",
        " exit : exits the shell\n",
		" env : prints the current environment\n",
		" _wich : looks for files in the current PATH\n"

    };
    while(*help_message[i])
    {
		write(1, help_message[i], strlen(help_message[i]));
		i++;
    }
}

/**
 *shell_cd - changes directory
 *Description :changes current directory for both child ansd parent
 *@args: argument lists 
 */

void shell_cd(char **args)
{
    if(args[1] == NULL)
    {
        perror("Hash: cd:missing arguments");
	}
    else
	{
		if(chdir(args[1]) != 0)
			perror("HAsh: cd");
	}
}
/*
* 
* 
*/
void shell_env(char** args __attribute__((unused)))
{
    extern char **environ;
    unsigned int i;

	printf("env func");
    for (i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
}
/*
* 
* 
*/
void shell_wich(char **args)
{
	struct stat st;
	unsigned int i;
	int err;
	
	for (i = 2; args[i] != NULL; i++)
	{
		err = stat(args[i], &st);

		if (err == 0)
		{
			printf("%s : FOUND\n", args[i]);
		}
		else
		{
			printf("%s : NOT FOUND\n", args[i]);
		}
	}
}