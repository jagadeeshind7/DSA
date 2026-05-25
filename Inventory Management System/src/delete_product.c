#include"../includes/header.h"

void delete_product()
{
    PRODUCT *temp, *prev;
    int id;

    if(head == NULL)
    {
        printf("No Products Available\n");
        return;
    }

    printf("Enter the product ID to Delete: ");
    scanf("%d", &id);

    temp = head;
    prev = NULL;

    while(temp)
    {
        if(temp->id == id)
        {
            if(temp == head)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            
            free(temp);

            printf("Product Deleted Successfully");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Product Not Found\n");
}