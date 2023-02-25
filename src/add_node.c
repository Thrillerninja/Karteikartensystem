//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "add_node.h"

// add a node to the list at the front
Node *addNodeF(int data,Node * head)
{
    Node *newNode = NULL;
    if (head == NULL) //if empty
    {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL)
            return NULL;

        newNode->data = data;
        head = newNode;
        newNode->next = NULL;
    } else {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL)
            return NULL;

        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}

Node *addNodeB(int data,Node * head)
{
    Node *newNode = NULL;
    Node *ptr = head;
    if (head == NULL) //if empty
    {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL)
            return NULL;

        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
    } else {
        newNode = malloc(sizeof(Node));
        if (newNode == NULL)
            return NULL;

        newNode->data = data;
        newNode->next = NULL;

        while (ptr->next!= NULL) ptr = ptr->next;
        ptr->next = newNode;
    }
    return head;
    /*
    // temporary structure
    Node *temp = NULL;
    temp = malloc(sizeof(Node));

    //fill the structure with data
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        //if (temp == NULL)
        //    return NULL;

        head = temp;
    } else {
        //if (temp == NULL)
        //    return NULL;

        ptr = head;
        while (ptr->next!= NULL) ptr = ptr->next;
        ptr->next = temp;
    }
    return head;*/
}

// insert a node into a position in the list
Node *insertNode(int data, int position, Node * head)   //TODO: fix always inserting at position 2
{
    Node *current = head;
    while (position != 0)
    {
        current = current->next;
        position--;
        if (current == NULL){
            printf("Requested position too far into list\n");
            printf("Failed to insert into list\n");
            return head;
        }
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return head;
    }

    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

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
    return head;
}
