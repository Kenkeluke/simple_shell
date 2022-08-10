#include "main.h"

/**
* main - prints "$ ", wait for the user to enter a command, execute it
* Return: 0 on success. -1 otherwise
*/
int main()
{

	int err;
	size_t linesize = 0;
	unsigned int n_word, i;
	
	while (1)
	{

		char *line = NULL, **words = NULL;
		
		n_word = 0;
		printf("($) ");
		/*read the line and set the line buffer and the linesize*/
		err = rline(&line, &linesize);

		/*if line is just a '\n' or rline failed*/
		if (*line == '\n' || err == -1)
		{
			free(line);
			line = NULL;

			continue;
		}

		/* split the line given into words */
		words = split(line, &n_word, linesize);
		printf("num of words = %u\n", n_word);
		
		/* if first word is "_wich"*/
		if (!strcmp(words[0], "_wich"))
		{
			/*for every word after wich*/
			for (i = 1; i < n_word; i++)
			{
				
				_check(words[i]);
			}
			free(words);
			free(line);
			continue;
		}
		/* if first word is _getenv */
		else if (strcmp(words[0], "_getenv") == 0)
		{
			/*for every env variable written after _getenv*/
			for (i = 1; i < n_word; i++)
			{
				printf("%s -> %s\n", words[0], _getenv(words[i]));
			}
			free(words);
			free(line);
			continue;
		}
		else
		/*execute the command*/
		err = exec(words);
		if (err == -1)
		{
			printf("error in execution\n");
		}
		free(words);
		free(line);
		words = NULL;
		line = NULL;
	}
	
}
