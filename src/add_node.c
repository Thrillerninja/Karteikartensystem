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
}

// insert a node into a position in the list
Node *insertNode(int data, int position, Node * head)
{
    if (head == NULL && position != 0)
    {
        printf("Requested position too far into list\n");
        printf("Failed to insert into list\n");
        return head;
    }

    Node *current = head;
    while (position > 1 && current != NULL)
    {
        current = current->next;
        position--;
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Failed to allocate memory");
        return head;
    }

    newNode->next = current->next;
    newNode->data = data;
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
