//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// remove a node from the list
Node *removeNode(int data, Node *head, Node *ptr)
{
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        if (current->data == data)
        {
            // temporary structure
            Node *temp = current->next;

            //delete the node
            free(current);

            if (prev == NULL) {
                head = temp;
            } else {
                prev->next = temp;
            }
            break;
        }
        prev = current;
        current = current->next;
    }
    return head;
}