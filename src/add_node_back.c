//
// Created by rorba on 09.02.2023.
//
// add a node to the list at the back

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "add_node_back.h"

Node *addNodeB(int data,Node * head,Node * ptr)
{
    // temporary structure
    Node *temp = NULL;
    temp = malloc(sizeof(Node));

    //fill the structure with data
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        //if (temp == NULL)
        //    return NULL;

        head = temp;
    } else {
        //if (temp == NULL)
        //    return NULL;

        ptr = head;
        while (ptr->next!= NULL) ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}