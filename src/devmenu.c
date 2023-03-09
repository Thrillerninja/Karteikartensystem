//
// Created by rorba on 08.03.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "devmenu.h"

#include "node.h"
#include "add_node.h"
#include "remove_node.h"
#include "swap_node.h"
#include "sort_node.h"
#include "print_list.h"
#include "file_handling.h"
#include "abfrage.h"
#include "asciart.h"

void printMenu(int style){
    if (style == 1) {
        printf("You have the following options:\n");
        printf("\t1. Add a node to the start of the list.\n");
        printf("\t2. Add a node at the end of the list.\n");
        printf("\t3. Remove a node from the list.\n");
        printf("\t4. Insert a node to the list.\n");
        printf("\t5. Print your list\n");
        printf("\t6. Change data in the list\n");
        printf("\t7. Search for a node in the list\n");
        printf("\t8. Push node\n");
        printf("\t9. DEPRECATED: Pull node\n");
        printf("\t10.Sort by times correctly answered\n");
        printf("\t11.Load from file\n");
        printf("\t12.Save to file\n");
        printf("\t13.Exit\n");
    }else{
        printf("You have the following options:\n");
        printf("\t1. Add a node to the start of the list.       7. Search for a node in the list\n");
        printf("\t2. Add a node at the end of the list.         8. Push node\n");
        printf("\t3. Remove a node from the list.               9. DEPRECATED: Pull node\n");
        printf("\t4. Insert a node to the list.                 10. Sort by times correct\n");
        printf("\t5. Print your list.                           11. Load from file\n");
        printf("\t6. Change data in the list                    12. Save to file\n");
        printf("\t                                              13. Exit\n");
    }
}

void clearTerminal(int lines){
    for (int i = 0; i < lines; i++){
        printf("\n");
    }
}

int devMenu()
{
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_QUESTION_LENGTH];
    int arg1 = 0;
    int arg2 = 0;
    int option = 0;

    Node *head = NULL;
    Node *ptr = NULL;

    system("cls");
    while (1)
    {
        printMenu(0);
        scanf("%d", &option);
        switch(option)
        {
            case 0:
                //start the abfrage
                system("cls"); //TODO: RETURN TO MAIN PROGRAM
                return 0;
            case 1:
                // add operation
                getchar(); //empties the input buffer so that no newline char remains in the buffer
                // complex operation to read data from user needed for allowing spaces in question and answer
                printf("What question should I insert?:\n");
                fgets(question, MAX_QUESTION_LENGTH, stdin);  // read input string with spaces
                question[strcspn(question, "\n")] = '\0';  // remove trailing newline character

                printf("What answer should I insert?:\n");
                fgets(answer, MAX_ANSWER_LENGTH, stdin);  // read input string with spaces
                answer[strcspn(answer, "\n")] = '\0';  // remove trailing newline character

                head = addNodeF(question, answer, arg1, head);
                break;

            case 2:
                // add operation
                printf("What question should I insert?:\n");
                scanf("%s", &question);
                printf("What answer should I insert?:\n");
                scanf("%s", &answer);
                head = addNodeB(question, answer,arg1, head);
                break;

            case 3:
                // remove operation
                printf("What question should I remove?:\n");
                scanf("%s", &question);
                head = removeNode(question, head);
                break;

            case 4:
                // insert operation
                printf("What question should I insert?:\n");
                scanf("%s", &question);
                printf("What answer should I insert?:\n");
                scanf("%s", &answer);
                printf("What times_correct should I insert?:\n");
                scanf("%d", &arg1);
                printf("What position?:\n");
                scanf("%d", &arg2);
                head = insertNode(question,answer,arg1, arg2, head);
                break;

            case 5:
                // print the list
                printList(head);
                break;

            case 6:
                // change operation
                printf("times_correct of what question should I change?:\n");
                scanf("%s", &question);
                printf("To what?:\n");
                scanf("%d", &arg2);
                head = setValue(question, arg2, head);
                if (head == NULL)
                    printf("Failed to change value\n");
                break;

            case 7:
                // searchNode operation
                printf("What question should be searched for?:\n");
                scanf("%s", &question);
                int position = searchNode(question, head);
                if (position == -1){
                    printf("Not found\n");
                }else{
                    Node *ptr = head;
                    int temp_position = position;
                    while (position != 0){
                        ptr = ptr->next;
                        position--;
                    }
                    printf("%s with answer: %s and times_correct: %d is the at position %d in the list\n",ptr->question, ptr->answer, ptr->times_correct, temp_position);
                }
                break;

            case 8:
                // swap operation
                printf("What question should be searched for?:\n");
                scanf("%s", &question);
                head = swap(searchNode(question,head), head);

                /*case 9:
                    // pull operation
                    printf("What question should be searched for?:\n");
                    scanf("%s", &question);
                    head = pull(question, head);
                    if (head == NULL)
                        printf("Failed to change value\n");
                    break;*/

            case 10:
                head = sort(head);
                printList(head);
                break;

            case 11:
                head = loadData(head); //TODO: inspect
                printf("Load from file\n");
                break;

            case 12:
                saveData(head);
                printf("Save to file\n");
                break;

            case 13:
                confirmExit();
                break;

            default:
                break;
        }
    }
}
