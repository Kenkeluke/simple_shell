#include "main.h"
/**
* main - prints "$ ", wait for the user to enter a command, execute it
*@ac: number of arguments
*@av: argument list
*@env: environment
* Return: 0 on success. -1 otherwise
*/
int main(int ac __attribute__((unused)), char **av, char **env)
{
	int active;

	environ = env;
	signal(SIGINT, sighand);

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

		if (words == NULL || line == NULL || words[1] == NULL)
		{
			free(line);
			free(words);
			continue;
		}

		if (checkbuilt(words) != 0)
		{
			exec(words);
		}
		free(words);
		free(line);

		if (!active)
			break;
	}
	return (0);
}
