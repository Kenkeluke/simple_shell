#include "main.h"
/**
* rline - reads a single line from stdin
* Return: the string of the line
*/
void rline(char **line)
{
	size_t linesize = 0;

	/*getline from stdin */
	if ( (getline(line, &linesize, stdin) == -1))
	{
		free(line);
		exit(0);
	}
}