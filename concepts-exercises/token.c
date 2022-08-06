#include "main.h"
/**
 *Split - splits a string into tokens
 *
 *@string: the string to be tokenised by a delimiter
 *
 *
 *
 *
 */

char *split(char *string)
{
	char *token;
	char *separator = " ";

	token = strtok( string, separator);

	while(token)
	{
		printf("%s \n", token);
		
		token = strtok(NULL, separator);
	}

	return (token);


}
