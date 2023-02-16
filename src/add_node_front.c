//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "add_node_front.h"

// add a node to the list at the front
Node *addNodeF(int data,Node * head)
{
    Node *new = NULL;
    // two cases:

    // if the list is empty.
    if (head == NULL)
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;

        new->data = data;
        head = new;
        new->next = NULL;
    } else {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;

        new->data = data;
        new->next = head;
        head = new;
    }

    return new;
}