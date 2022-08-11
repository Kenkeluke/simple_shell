#include "main.h"
/**
* getenv - gets an environment variable
* @name: name of the environment variable
* Return: a pointer to a string with the value
*			null if the env variable doesn't exist
*/
char *_getenv(const char *name)
{
	unsigned int i, k, _strlen;

	char *value ;

	_strlen = strlen(name);

	k = _strlen + 1;

	/* loop for every envron variable */
	for (i = 0; environ[i] != NULL; i++)
	{
		/* if the name is the same as variable name */
		if (!strncmp(environ[i], name, _strlen))
		{
			value = &(environ[i][k]);
			return (value);
		}
	}
	return (NULL);
}