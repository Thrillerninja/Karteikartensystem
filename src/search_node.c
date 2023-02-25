//
// Created by rorba on 09.02.2023.
//
// add a node to the list at the back

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void search(int data, Node * head) {
    Node *current = head;
    int position = 0;
    int found = 0;
    while (current!= NULL)
    {
        if (current->data == data)
        {
            printf("%d is the at position %d in the list\n",data,position+1);
            found = 1;
        }
        current = current->next;
        position ++;
    }
    if (found == 0) {
        printf("Not found\n");
    }
}