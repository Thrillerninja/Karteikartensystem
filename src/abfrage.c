//
// Created by rorba on 17.02.2023.
//

#include <stdio.h>
#include "node.h"

Node *abfrageStart(Node *head){

}

int searchNode(int data, Node * head) {
    Node *current = head;
    int position = 0;
    while (current!= NULL)
    {
        if (current->data == data)
        {
            return position;
        }
        current = current->next;
        position ++;
    }
    return -1;
}