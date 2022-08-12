#include "main.h"
/**
* split - splits a string into words
* @line: the string to be splitted
* @file: the file name
* Return: an array of each word of the string
*/
char **split(char *line, char *file)
{
	char *delim = "\n \t";
	unsigned int  i = count_tokens(_strdup(line), delim);
	char **array = malloc((i + 2) * sizeof(char *));
	char *token = strtok(line, delim);
	

	if (array == NULL)
	{
		free(array);
		return (NULL);
	}

	array[0] = file;
	array[1] = token;
	for (i = 1; token != NULL; i++)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		array[i + 1] = token;
	}


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

