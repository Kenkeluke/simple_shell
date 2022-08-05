#include "main.h"

/**
 * line-reader: A funtion that reads each line passed
 * to the standard input
 *
 *
 *
 *
 *
 */

int main(void)
{
	char prompt[] = "$$ ";
	char* line = NULL;
	size_t line_size = 0;
	ssize_t return_value;
	write(1, prompt, 3);
	return_value = getline(&line, &line_size, stdin);
	write(1, line, line_size);
	free(line);

	return 0;
}
