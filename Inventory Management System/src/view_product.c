#include"../includes/header.h"

void view_products()
{
	PRODUCT *temp;

	if(head == NULL)
	{
		printf("No Products Available\n");
		return;
	}

	temp = head;

	printf("\n===== PRODUCT LIST =====\n");

	while(temp != NULL)
	{
		printf("\nID        :%d\n", temp->id);
		printf("\nName      :%s\n", temp->name);
		printf("\nQuantity  :%d\n", temp->quantity);
		printf("\nPrice     :%.2f\n", temp->price);
		printf("\n");

		temp = temp->next;
	}
}
