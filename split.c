#include "main.h"
/**
* split - splits a string into words
* @line: the string to be splitted
*
* Return: an array of each word of the string
*/
char **split(char *line)
{
	char *delim = "\n \t";

	unsigned int  i = count_tokens(_strdup(line), delim);
	
	char **array = malloc(i * sizeof(char *) + 1);
	char *token = strtok(line, delim);


	if (array == NULL || token == NULL)
	{
		free(array);
		return (NULL);
	}

	array[0] = token;
	for (i = 1; token != NULL; i++)
	{
		token = strtok(NULL, delim);
		array[i] = token;
	}
	array[i] = NULL;

	return (array);
}
/**
* count_tokens - count number of tokens
* @line: a copy of the original line
* @sep: the string separator
* Return: number of tokens
*/
unsigned int count_tokens(char *line, char *sep)
{
	unsigned int i;

	char *token = strtok(line, sep);

	for (i = 0; token != NULL; i++)
	{
		token = strtok(NULL, sep);
	}
	free(line);
	return (i);
}

