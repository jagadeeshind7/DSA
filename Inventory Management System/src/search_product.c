#include "../includes/header.h"

void search_product()
{
       PRODUCT *temp;
       int id;
	
       if(head == NULL)
       {
	printf("No Products Available\n");
	return;
       }

       printf("Enter Product ID to search: ");
       scanf("%d", &id);

       temp = head;

       while(temp)
       {
	if(temp->id == id)
	{
	printf("\n Product Found\n");

	printf("ID          :%d\n", temp->id);
	printf("Name        :%s\n", temp->name);
	printf("Quantity    :%d\n", temp->quantity);
        printf("Price       :%.2f\n", temp->price);
        
	return;
	}
	temp = temp->next;
      }
	printf("Product Not Found\n");
}

