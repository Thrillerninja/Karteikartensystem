//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "insert_node.h"

// insert a node into a position in the list
Node *insertNode(int data, int position, Node * head)   //TODO: fix always inserting at position 2
{
    Node *current = head;
    while (current != NULL && position != 0)
    {
        position--;
    }

    if (position != 0)
    {
        printf("Requested position too far into list\n");
        return NULL;
    }

    Node *new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;

    new->data = data;
    new->next = current->next;
    current->next = new;

    return current;
}