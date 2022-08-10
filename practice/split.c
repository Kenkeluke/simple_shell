#include "main.h"
/**
* split - splits a string into words
* @line: the string to be splitted
* @n_word: the address of n_word variable
* @linesize: the sizeof the line given by getline
* 
* Return: an array of each word of the string
*/
char **split(char *line)
{
	char **array;
	char *delim = "\n ";
	char *token = strtok(line, delim);
	void *p = NULL;
	unsigned int n_word, i;


	array = malloc(	1 * sizeof(char*));
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}

	/*fill the array with tokens from the line*/
	array[0] = token;
	n_word = 1;
	printf("word -> %s\n", array[0]);

	for (i = 1; token != NULL; i++)
	{
		array = _realloc(p, i, i+1);
		printf("%s\n", array[i]);
		token = strtok(NULL, delim);
		array[i] = token;

		printf("word -> %s\n", array[i]);
		n_word++;
	}
	printf("array reallocated with size %u\n", i - 1);
	printf("num of words = %u\n", n_word - 1);
	return (array);
}

