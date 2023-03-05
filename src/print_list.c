//
// Created by rorba on 16.02.2023.
//
#include "stdio.h"
#include "node.h"

void printList(Node * head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("[%s, %s, %d] -> ", current->question,current->answer,current->times_correct);
        current = current->next;
    }

    printf("\n");
}