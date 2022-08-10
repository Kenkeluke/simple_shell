#include "main.h"

/**
* main - prints "$ ", wait for the user to enter a command, execute it
* Return: 0 on success. -1 otherwise
*/
int main()
{

	int err;

	
	while (1)
	{
		char *line = NULL, **words = NULL;
		

		_puts("($) ");
		/*read the line and set the line buffer and the linesize*/
		rline(&line);

		/*if line is just a '\n' or rline failed*/
		if (*line == '\n')
		{
			free(line);
			continue;
		}

		/* split the line given into words */
		words = split(line);


		if (checkbuilt(words) == 0)
		{
			printf("executed\n");
			free(words);
			free(line);
			continue;
		}

		/*execute the command*/
		err = exec(words);
		if (err == -1)
		{
			printf("error in execution\n");
		}
		free(words);
		words = NULL;
		line = NULL;
	}
	
}
