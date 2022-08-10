#include "main.h"
/**
* split - splits a string into words
* @line: the string to be splitted
* @n_word: the address of n_word variable
* @linesize: the sizeof the line given by getline
* 
* Return: an array of each word of the string
*/
char **split(char *line,unsigned int *n_word, size_t linesize)
{	char **array;
	size_t  i;
	char *delim = "\n ";
	char *token = strtok(line, delim);

	/* malloc with the size of linesize (usually 120) */
	array = malloc(linesize * sizeof(char*));

	/*fill the array with tokens from the line*/
	for (i = 0, array[0] = token ; token != NULL; i++)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		(*n_word)++;
		printf("word -> %s\n", array[i]);
	}

	/*reallocate with the new size plus 1 for null*/
	array = realloc(array, (*n_word) + 1);

	/*put null pointer at the end of the array*/
	array[i] = NULL;

	printf("array reallocated with size %u\n", (*n_word) + 1);
	return (array);
}

