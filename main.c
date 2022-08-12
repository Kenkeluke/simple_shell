#include "main.h"

/**
* main - prints "$ ", wait for the user to enter a command, execute it
* Return: 0 on success. -1 otherwise
*/
int main(int ac __attribute__((unused)), char **av, char **env)
{
	int active;

	environ = env;
	while (1)
	{
		char *line = NULL, **words = NULL;
		

		if (isatty(STDIN_FILENO) == 1)
		{
			_puts("($) ");
			active = 1;
		}
		else
		{
			active = 0;
		}
		rline(&line, active);
		words = split(line, av[0]);

		if (words == NULL || line == NULL || words [1] == NULL)
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

		free(words);
		free(line);
	}
	return (0);
}
