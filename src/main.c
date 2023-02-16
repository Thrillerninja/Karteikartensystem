#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "add_node_front.c"
#include "add_node_back.c"
#include "remove_node.c"
#include "insert_node.c"
#include "edit_node.c"
#include "search_node.c"
#include "swap_node.c"
#include "sort_node.c"
#include "print_list.c"
#include "file_handling.c"

void printMenu(int style){
    if (style ==1) {
        printf("You have the following options:\n");
        printf("\t1. Add a node to the start of the list.\n");
        printf("\t2. Add a node at the end of the list.\n");
        printf("\t3. Remove a node from the list.\n");
        printf("\t4. Insert a node to the list.\n");
        printf("\t5. Print your list\n");
        printf("\t6. Change data in the list\n");
        printf("\t7. Search for a node in the list\n");
        printf("\t8. Push node\n");
        printf("\t9. Pull node\n");
        printf("\t10.Sort by times correctly answered\n");
        printf("\t11.Load from file\n");
        printf("\t12.Save to file\n");
        printf("\t13.Exit\n");
    }else{
        printf("You have the following options:\n");
        printf("\t1. Add a node to the start of the list.       7. Search for a node in the list\n");
        printf("\t2. Add a node at the end of the list.         8. Push node\n");
        printf("\t3. Remove a node from the list.               9. Pull node\n");
        printf("\t4. Insert a node to the list.                 10. Sort by times correct\n");
        printf("\t5. Print your list.                           11. Load from file\n");
        printf("\t6. Change data in the list                    12. Save to file\n");
        printf("\t                                              13. Exit\n");
    }
}

void clearScreen(int lines){
    for (int i = 0; i < lines; i++){
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int option = -1;
    int arg1 = 0;
    int arg2 = 0;

    Node *head = NULL;
    Node *ptr = NULL;

    while (1)
    {
        printMenu(0);
        int num_received = scanf("%d", &option);
        switch(option)
        {
            case 1:
                // add operation
                printf("What data should I insert?:\n");
                scanf("%d", &arg1);
                head = addNodeF(arg1, head);
                break;

            case 2:
                // add operation
                printf("What data should I insert?:\n");
                scanf("%d", &arg1);
                head = addNodeB(arg1, head,ptr);
                break;

            case 3:
                // remove operation
                printf("What data should I remove?:\n");
                scanf("%d", &arg1);
                head = removeNode(arg1, head, ptr);
                break;

            case 4:
                // insert operation
                printf("What data should I insert?:\n");
                scanf("%d", &arg1);
                printf("What position?:\n");
                scanf("%d", &arg2);
                head = insertNode(arg1, arg2, head);
                if (head == NULL)
                    printf("Failed to insert into list\n");
                break;

            case 5:
                // print the list
                printList(head);
                break;

            case 6:
                // change operation
                printf("What data should changed?:\n");
                scanf("%d", &arg1);
                printf("To what?:\n");
                scanf("%d", &arg2);
                head = setValue(arg1, arg2, head);
                if (head == NULL)
                    printf("Failed to change value\n");
                break;

            case 7:
                // search operation
                printf("What data should be searched?:\n");
                scanf("%d", &arg1);
                search(arg1, head);
                break;

            case 8:
                // push operation
                printf("What data should be pushed backwards?:\n");
                scanf("%d", &arg1);
                head = push(arg1, head);
                if (head == NULL)
                    printf("Failed to change value\n");
                break;

            case 9:
                // pull operation
                printf("What data should be pulled forwards?:\n");
                scanf("%d", &arg1);
                head = pull(arg1, head);
                if (head == NULL)
                    printf("Failed to change value\n");
                break;

            case 10:
                head = sort(head);
                printList(head);
                break;

            case 11:
                printf("Load from file\n");

            case 12:
                printf("Save to file\n");

            case 13:
                clearScreen(10);
                exit(0);

            default:
                break;
        }
    }
}
