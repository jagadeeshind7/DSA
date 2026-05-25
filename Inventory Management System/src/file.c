#include"../includes/header.h"

void save_to_file()
{
    FILE *fp;
    PRODUCT *temp;

    fp = fopen(FILE_NAME,"wb");

    if(fp == NULL)
    {
        printf("File Open Failed\n");
        return;
    }

    temp = head;

    while(temp)
    {
        fwrite(temp, sizeof(PRODUCT), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
}

void load_from_file()
{
    FILE *fp;
    PRODUCT *newnode, *temp;

    fp = fopen(FILE_NAME, "rb");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        newnode = create_node();

        if(fread(newnode, sizeof(PRODUCT), 1,fp) != 1)
        {
            free(newnode);
            break;
        } 

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next !=NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
    
    fclose(fp);
}
