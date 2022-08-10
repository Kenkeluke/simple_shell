#include "main.h"
/*
* 
* 
*/
void* _realloc(void* ptr, unsigned int old_size, unsigned int new_size)
{
	char* p;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);

	if (new_size != 0 || ptr == NULL)
	{
		p = malloc(new_size);
		if (p != NULL)
		{
			if (ptr != NULL)
			{
				for (i = 0; i < new_size && i < old_size; i++)
					p[i] = *((char*)(ptr)+i);
			}
			free(ptr);
			return (p);
		}
	}
	free(ptr);
	return (NULL);
}

/*
* 
* 
*/
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}