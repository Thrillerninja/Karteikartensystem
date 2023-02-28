//
// Created by rorba on 09.02.2023.
//
//
#include <stdio.h>
#include "node.h"

Node *swap(int swap_position, Node * head)
{
    if (head == NULL || head->next == NULL) {   //if there is no list, there is no point in creating pointers to it
        printf("No List detected, cannot swap\n");
        return head;
    }

    Node *previous = NULL;
    Node *current = head;
    int position = 0;

    while (position != swap_position) { // goes to the swap position
        if(current->next == NULL) {     // if it isn´t existing
            printf("End of List reached without reaching the swap position, cannot swap\n");
            return head;
        }
        previous = current;
        current = current->next;
        position++;
    }

    if ( current->next == NULL){
        printf("Reached swap position, but no Element to swap with left in the List, cannot swap\n");
        return head;
    }

    Node *temp = current->next;
    current->next = temp->next;    // actual swap location
    temp->next = current;

    if (previous == NULL) {
        head = temp;
    } else {
        previous->next = temp;
    }
    return head;
}

/////////////////////////////////////////////////////////////////////////
Node *pushdata(int pushdata, Node * head)
{
    if (head == NULL ||head->next == NULL) {
        printf("No List detected, cannot swap\n");
        return head;
    }

    Node *previous = NULL;
    Node *current = head;
    int position = 0;

    while (current && current->data != pushdata) {
        if(current->next == NULL) {     // if it isn´t existing
            printf("End of List reached without reaching the swap position, cannot swap\n");
            return head;
        }
        previous = current;
        current = current->next;
    }

    if ( current->next == NULL){
        printf("Reached swap position, but no Element to swap with left in the List, cannot swap\n");
        return head;
    }

    Node *temp = current->next;
    current->next = temp->next;    // actual swap location
    temp->next = current;

    if (previous == NULL) {
        head = temp;
    } else {
        previous->next = temp;
    }
    return head;
}

Node *pull(int data, Node * head) {

    if (head == NULL ||head->next == NULL) {
        printf("End of List reached, cannot swap\n");
    }

    Node *previous = NULL;
    Node *current = head;

    while (current && current->data != 1) {
        previous = current;
        current = current->next;
    }

    if (current == NULL || current->next == NULL){
        return head;
    }

    Node *temp = current->next;     //create temp struct
    if (previous != NULL) previous->next = temp;        //
    else head = temp;

    current->next = temp->next;
    temp->next = current;
    return head;
}