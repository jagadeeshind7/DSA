// ======================= main.c =======================

#include "header.h"

int main()
{
    SLL *headptr = NULL;
    int op;

    while (1)
    {
        printf("\n\033[35m===== STUDENT DATABASE =====\033[0m\n");

        printf("\033[32m1  Add Begin\n");
        printf("2  Add End\n");
        printf("3  Add Middle\n");
        printf("4  Print Nodes\n");
        printf("5  Count Nodes\n");
        printf("6  Save File\n");
        printf("7  Read File\n");
        printf("8  Reverse Print\n");
        printf("9  Print Recursive\n");
        printf("10 Reverse Recursive\n");
        printf("11 Delete All\n");
        printf("12 Delete Node\n");
        printf("13 Search Node\n");
        printf("14 Sort Data\n");
        printf("15 Reverse Link\n");
        printf("16 Release Memory\n");
        printf("17 Exit\n");

        printf("\nEnter choice : ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                add_begin(&headptr);
                break;

            case 2:
                add_end(&headptr);
                break;

            case 3:
                add_middle(&headptr);
                break;

            case 4:
                print_node(headptr);
                break;

            case 5:
                printf("Total Nodes = %d\n", count_node(headptr));
                break;

            case 6:
                save_file(headptr);
                break;

            case 7:
                read_file(&headptr);
                break;

            case 8:
                reverse_print(headptr);
                break;

            case 9:
                print_rec(headptr);
                break;

            case 10:
                reverse_rec(headptr);
                break;

            case 11:
                delete_all(&headptr);
                break;

            case 12:
                delete_node(&headptr);
                break;

            case 13:
                search_node(headptr);
                break;

            case 14:
                sort_node(headptr);
                break;

            case 15:
                reverse_link(&headptr);
                break;

            case 16:
                release_memory(&headptr);
                break;

            case 17:
                exit(0);

            default:
                printf("\033[31mInvalid Choice\033[0m\n");
        }
    }
}


