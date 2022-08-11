#include "main.h"

/**
 * _check - checks the existence of a file in the current directory
 *
 * Return always 0;
 */
int _check(char *filename)
{
    struct stat st;
	int err = stat(filename, &st);

	if (err == 0)
		printf(" FOUND\n");
	else
		printf("NOT FOUND\n");
    return (0);

}
