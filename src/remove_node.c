//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// remove a node from the list
Node *removeNode(int data, Node *head)
{
    Node *current = head->next;
    Node *prev = head;

    if (head->times_correct == data){    // if first element needs to be removed (reduces number of necessary structs)
        Node *temp = head->next;
        free(head);
        return temp;
    }

    while (current != NULL) //returns directly if list is empty
    {
        if (current->times_correct == data)
        {
            prev->next = current->next;
            free(current); //delete the node
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}