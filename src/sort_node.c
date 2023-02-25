//
// Created by rorba on 09.02.2023.
//
// add a node to the list at the back

#include <stdio.h>
#include "node.h"
#include "swap_node.h"

Node *sort(Node * head) {
    Node *ptr = head;

    int list_length = 0;
    while(ptr->next != NULL) {  // calculate the list length
        list_length++;
        ptr = ptr->next;
    }
    printf("Elements in the List: %d\n", list_length+1);

    for (int i = 0; i < list_length; i++) { //loops threw max number of sorting steps
        Node *previous = NULL;
        Node *current = head;

        for (int j = 0; j < list_length - i; j++) { //loops threw every element and swaps if needed
            Node *next_node = current->next;
            if (current->data > next_node->data) {  //compares values
                head = swap(j, head);   //swaps
                if (j == 0) {
                    current = head;
                } else {
                    current = previous->next;
                }
                next_node = current->next;
            }
            previous = current;
            current = next_node;
        }
    }
    return head;
}