#include "main.h"
/**
* rline - reads a single line from stdin
* @line: the line input
* @interactive: 1 if interactive, 0 otherwise
* Return: the string of the line
*/
void rline(char **line, int interactive)
{
	size_t linesize = 0;
	int bytes_read;

	bytes_read = getline(line, &linesize, stdin);
	/*getline from stdin */
	if ((bytes_read == -1))
	{
		if (interactive)
		{
			free(line);
		}
		exit(0);
	}

}
