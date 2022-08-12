#include "main.h"

/**
* main - prints "$ ", wait for the user to enter a command, execute it
* Return: 0 on success. -1 otherwise
*/
int main(int ac __attribute__((unused)), char **av)
{


	while (1)
	{
		char *line = NULL, **words = NULL;

		_puts("($) ");
		rline(&line);

		words = split(line, av[0]);

		if (words == NULL || line == NULL)
		{
			free(line);
			free(words);
			continue;
		}

		if (checkbuilt(words) == 0)
		{
			free(words);
			free(line);
			continue;
		}

		exec(words);

		free(line);
		free(words);
		words = NULL;
		line = NULL;
	}
}
