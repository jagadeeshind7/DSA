#include "../includes/header.h"

void add_product()
{
	PRODUCT *newnode, *temp;

	newnode = create_node();

	printf("Enter Product ID: ");
	scanf("%d", &newnode->id);

	printf("Enter Product Name: ");
	scanf(" %[^\n]", newnode->name);

	printf("Enter Quantity: ");
	scanf(" %d", &newnode->quantity);

	printf("Enter Price: ");
	scanf(" %f", &newnode->price);

	if(head == NULL)
	{
	head = newnode;
	}
	else
	{
	temp = head;

	while(temp->next != NULL)
	{
	temp = temp->next;
	}
        
	temp->next = newnode;
	}

	printf("Product Added Successfully\n");
	
}
