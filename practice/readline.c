#include "main.h"
/**
* rline - reads a single line from stdin
* Return: the string of the line
*/
int rline(char **line, size_t *linesize)
{
	int bytes_read;
	/*getline from stdin */
	bytes_read = getline(line, linesize, stdin);
	return (bytes_read);
}