#include "../includes/header.h"

PRODUCT *create_node()
{

	PRODUCT *newnode;

	newnode = (PRODUCT *)malloc(sizeof(PRODUCT));

	if(newnode == NULL)
	{
		printf("Memory Allocation Failed\n");
		exit(0);
	}

	newnode->next = NULL;

	return newnode;

}
