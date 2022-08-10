#include "main.h"

/**
* printpath - prints each directory contained in the environment variable PATH
* @str: the value of the path
*/
path *listpath()
{
	char *pathvalue = _getenv("PATH");
	char *token = strtok(pathvalue, ":");
	unsigned int i;
	path *tail;
	path *head = malloc(sizeof(path));
	

	if (pathvalue == NULL || head == NULL)
	{
		printf("pathvalue is empty");
		free(head);
		return(NULL);
	}

	head->str = pathvalue;
	head->next = NULL;
	tail = head;
	for (i = 0; token != NULL; i++)
	{
		tail = add_node_end(tail, token);
		printf("%s\n", tail->str);
		token = strtok(NULL, ":");
	}
	printf("tail is %s %p\n", tail->str,(void*) tail->next);
	return (head);
}


path *add_node_end(path *tail,char *tok)
{
	path *new = malloc(sizeof(path));
	
	if (tok == NULL || tail == NULL)
	{
		free(new);
		printf("there is no nodes");
		return (NULL);
	}
	new->str = tok;
	new->next = NULL;
	tail->next = new;
	return (new);
}


void free_list(path *head)
{
	path *tmp;


	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}