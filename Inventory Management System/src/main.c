#include "../includes/header.h"

PRODUCT *head = NULL;

int main()
{
	int choice;

	load_from_file();


	while(1)
	{
		printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");

		printf("\n1. Add product\n");
		printf("2. View product\n");	
		printf("3. Search product\n");	
		printf("4. Update product\n");
		printf("5. Delete product\n");
		printf("6. Save Data\n");
		printf("7. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				add_product();
				break;

			case 2:
				view_products();
				break;
                           
			case 3:
				search_product();
				break;

			case 4:
				update_product();
				break;

			case 5:
				delete_product();
				break;

			case 6:
				save_to_file();
				break;

			case 7:
				save_to_file();
				printf("Data Saved Successfully\n");
				exit(0);

			default:
				printf("Invaild choice\n");


		}
 

	}	
}

