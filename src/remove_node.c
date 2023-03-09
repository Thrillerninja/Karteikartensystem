//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// remove a node from the list
Node *removeNode(char question[], Node *head)
{
    Node *current = head->next;
    Node *prev = head;

    if (strcmp(head->question,question) == 0){    // if first element needs to be removed (reduces number of necessary structs)
        Node *temp = head->next;
        free(head);
        return temp;
    }

    while (current != NULL)
    {
        if (strcmp(head->question,question) == 0)
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