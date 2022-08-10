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
	char *delim = " ";
	void *p = NULL;
	unsigned int n_word = 1, i;
	char **array = malloc( n_word * sizeof(char *));
	char *token = strtok(line, delim);

	
	
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}

	/*fill the array with tokens from the line*/
	array[0] = token;
	printf("word -> %s\n", array[0]);

	for (i = 1; token != NULL; i++)
	{
		
		token = strtok(NULL, delim);
		if (token != NULL)
		{
			n_word++;
			array = realloc(array, n_word * sizeof(char *));
			array[i] = token;
			printf("word -> %s\n", array[i]);
			
		}
		
		
	}
	printf("array reallocated with size %u\n", i - 1);
	printf("num of words = %u\n", n_word - 1 );
	return (array);
}

