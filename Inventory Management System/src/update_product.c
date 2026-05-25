#include "../includes/header.h"

void update_product()
{
	PRODUCT *temp;
	int id;

	if (head == NULL)
	{
		printf("No Products Available");
		return;
	}
	printf("Enter Product ID to update: ");
	scanf("%d", &id);

	temp = head;

	while (temp)
	{
		if (temp->id == id)
		{
			printf("Enter New Name: ");
			scanf(" %[^\n]", temp->name);

			printf("Enter New Quantity: ");
			scanf(" %d", &temp->quantity);

			printf("Enter New Price: ");
			scanf(" %f", &temp->price);

			printf("Product Updated Successfully\n");
			return;
		}
		temp = temp->next;
	}
	printf("Product Not Found\n");
}
