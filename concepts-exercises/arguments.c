#include "main.h"
/**
*main- the main function takes two parameters from the CI and executes
*@argc:number of command line arguments
*@_attribute_((unused)): unsused parameter
*@argv: command line arguments
*return:0 as always
*/

int main(int argc __attribute__((unused)), char *argv[])
{
int i;
	for (i = 1; argv[i]; i++)
	{
		printf("Argument number %d = %s \n", i,  argv[i]);
	}
	return (0);
}
