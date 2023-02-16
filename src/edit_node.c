//
// Created by rorba on 09.02.2023.
//
// add a node to the list at the back

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "edit_node.h"

// set a node value
Node *setValue(int data ,int value, Node *head) {
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            current->data = value;
            return head;
        }
        current = current->next;
    }
}
