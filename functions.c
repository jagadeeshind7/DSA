// ======================= functions.c =======================

#include "header.h"

// ------------------------------------------------------------
// Add Begin
void add_begin(SLL **ptr)
{
    SLL *new = malloc(sizeof(SLL));

    printf("Enter rollno name marks : ");
    scanf("%d %s %f", &new->rollno, new->name, &new->marks);

    new->next = *ptr;
    *ptr = new;
}

// ------------------------------------------------------------
// Add End
void add_end(SLL **ptr)
{
    SLL *new = malloc(sizeof(SLL));

    printf("Enter rollno name marks : ");
    scanf("%d %s %f", &new->rollno, new->name, &new->marks);

    new->next = NULL;

    if (*ptr == NULL)
    {
        *ptr = new;
    }
    else
    {
        SLL *last = *ptr;

        while (last->next)
            last = last->next;

        last->next = new;
    }
}

// ------------------------------------------------------------
// Add Middle
void add_middle(SLL **ptr)
{
    int pos, i;

    printf("Enter position : ");
    scanf("%d", &pos);

    if (pos <= 1 || *ptr == NULL)
    {
        add_begin(ptr);
        return;
    }

    SLL *new = malloc(sizeof(SLL));

    printf("Enter rollno name marks : ");
    scanf("%d %s %f", &new->rollno, new->name, &new->marks);

    SLL *temp = *ptr;

    for (i = 1; i < pos - 1 && temp->next; i++)
        temp = temp->next;

    new->next = temp->next;
    temp->next = new;
}

// ------------------------------------------------------------
// Print Nodes
void print_node(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No Records Found\n");
        return;
    }

    while (ptr)
    {
        printf("%d %s %.2f\n",
               ptr->rollno,
               ptr->name,
               ptr->marks);

        ptr = ptr->next;
    }
}

// ------------------------------------------------------------
// Count Nodes
int count_node(SLL *ptr)
{
    int c = 0;

    while (ptr)
    {
        c++;
        ptr = ptr->next;
    }

    return c;
}

// ------------------------------------------------------------
// Save File
void save_file(SLL *ptr)
{
    FILE *fp = fopen("std.txt", "w");

    if (fp == NULL)
    {
        printf("File Open Error\n");
        return;
    }

    while (ptr)
    {
        fprintf(fp,
                "%d %s %f\n",
                ptr->rollno,
                ptr->name,
                ptr->marks);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Data Saved Successfully\n");
}

// ------------------------------------------------------------
// Read File
void read_file(SLL **ptr)
{
    FILE *fp = fopen("std.txt", "r");

    if (fp == NULL)
    {
        printf("File Not Found\n");
        return;
    }

    while (1)
    {
        SLL *new = malloc(sizeof(SLL));

        if (fscanf(fp,
                   "%d %s %f",
                   &new->rollno,
                   new->name,
                   &new->marks) == EOF)
        {
            free(new);
            break;
        }

        new->next = NULL;

        if (*ptr == NULL)
        {
            *ptr = new;
        }
        else
        {
            SLL *last = *ptr;

            while (last->next)
                last = last->next;

            last->next = new;
        }
    }

    fclose(fp);

    printf("File Read Successfully\n");
}

// ------------------------------------------------------------
// Reverse Print
void reverse_print(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No Records\n");
        return;
    }

    int c = count_node(ptr);

    for (int i = c; i >= 1; i--)
    {
        SLL *temp = ptr;

        for (int j = 1; j < i; j++)
            temp = temp->next;

        printf("%d %s %.2f\n",
               temp->rollno,
               temp->name,
               temp->marks);
    }
}

// ------------------------------------------------------------
// Print Recursive
void print_rec(SLL *ptr)
{
    if (ptr == NULL)
        return;

    printf("%d %s %.2f\n",
           ptr->rollno,
           ptr->name,
           ptr->marks);

    print_rec(ptr->next);
}

// ------------------------------------------------------------
// Reverse Recursive
void reverse_rec(SLL *ptr)
{
    if (ptr == NULL)
        return;

    reverse_rec(ptr->next);

    printf("%d %s %.2f\n",
           ptr->rollno,
           ptr->name,
           ptr->marks);
}

// ------------------------------------------------------------
// Delete All
void delete_all(SLL **ptr)
{
    SLL *del;

    while (*ptr)
    {
        del = *ptr;
        *ptr = del->next;

        free(del);
    }

    printf("All Nodes Deleted\n");
}

// ------------------------------------------------------------
// Delete Node
void delete_node(SLL **ptr)
{
    if (*ptr == NULL)
    {
        printf("No Nodes Present\n");
        return;
    }

    int roll;

    printf("Enter rollno to delete : ");
    scanf("%d", &roll);

    SLL *del = *ptr;
    SLL *prev = NULL;

    while (del)
    {
        if (del->rollno == roll)
        {
            if (prev == NULL)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);

            printf("Node Deleted\n");
            return;
        }

        prev = del;
        del = del->next;
    }

    printf("Rollno Not Found\n");
}

// ------------------------------------------------------------
// Search Node
void search_node(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No Records\n");
        return;
    }

    char name[20];
    int f = 0;

    printf("Enter name : ");
    scanf("%s", name);

    while (ptr)
    {
        if (strcmp(name, ptr->name) == 0)
        {
            printf("%d %s %.2f\n",
                   ptr->rollno,
                   ptr->name,
                   ptr->marks);

            f = 1;
        }

        ptr = ptr->next;
    }

    if (f == 0)
        printf("Name Not Found\n");
}

// ------------------------------------------------------------
// Sort Nodes
void sort_node(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No Records\n");
        return;
    }

    SLL *p1, *p2;
    int temp_roll;
    char temp_name[20];
    float temp_marks;

    for (p1 = ptr; p1 != NULL; p1 = p1->next)
    {
        for (p2 = p1->next; p2 != NULL; p2 = p2->next)
        {
            if (p1->rollno > p2->rollno)
            {
                temp_roll = p1->rollno;
                strcpy(temp_name, p1->name);
                temp_marks = p1->marks;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->marks = p2->marks;

                p2->rollno = temp_roll;
                strcpy(p2->name, temp_name);
                p2->marks = temp_marks;
            }
        }
    }

    printf("Sorting Completed\n");
}

// ------------------------------------------------------------
// Reverse Link
void reverse_link(SLL **ptr)
{
    SLL *prev = NULL;
    SLL *current = *ptr;
    SLL *next;

    while (current)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    *ptr = prev;

    printf("Links Reversed\n");
}

// ------------------------------------------------------------
// Release Memory
void release_memory(SLL **ptr)
{
    delete_all(ptr);
    printf("Memory Released\n");
}

//--------------------------------------------------------------
