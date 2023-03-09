//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include "node.h"
#include "swap_node.h"

Node *sort(Node * head) {
    if (head == NULL || head->next == NULL){ // sort not needed
        return head;
    }

    Node *ptr = head;

    // calculate the list length
    int list_length = 0;
    while(ptr->next != NULL) {
        list_length++;
        ptr = ptr->next;
    }
    printf("Elements in the List: %d\n", list_length+1);

    // Sort the list using bubble sort
    for (int i = 0; i < list_length; i++) {
        Node *previous = NULL;
        Node *current = head;

        for (int j = 0; j < list_length - i; j++) { //loops threw every element and swaps if needed
            Node *next_node = current->next;
            if (current->times_correct > next_node->times_correct) {  //compares values
                head = swap(j, head);   // Swaps the current and next nodes
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