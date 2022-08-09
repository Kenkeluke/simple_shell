#include "main.h"
/**
 *shell_exit - exits the shell and returns back to the original shell
 *Description : uses the exit function 
 *@args: argument lists 
 *Return: void 
 */

void shell_exit(char **args)
{
    exit(0);
}

/**
 *shell_help - Displays help message in shell
 *Description :Displays navigation message
 *@args: argument lists 
 *Return: void 
 */

void shell_help(char **args)
{
    int i;
    char *help_message[] = 
    {
        "Welcome to a simple shell built by Arafah and Kenkeluke\n",
        "The Following built-ins are supported:\n",
        " cd : change current working directory\n",
        " help : displays this help message\n",
        " exit : exits the shell\n"

    };
    i = 0;
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
 *Return: void 
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