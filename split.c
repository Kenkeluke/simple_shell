#include "main.h"
/**
* split - splits a string into words
* @line: the string to be splitted
*
* Return: an array of each word of the string
*/
char **split(char *line)
{
	char *delim = "\n ";
	void *p = NULL;
	unsigned int n_word = 1, i;
	char **array = malloc(n_word * sizeof(char *));
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
			array = _realloc(p, n_word - 1, n_word);
			array[i] = token;
			printf("word -> %s\n", array[i]);

		}

	}
	free(line);
	printf("array reallocated with size %u\n", n_word);
	array[n_word] = NULL;

	return (array);
}

