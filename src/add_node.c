//
// Created by rorba on 09.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "add_node.h"

// add a node to the list at the front
Node *addNodeF(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, Node * head)
{
    Node *newNode = NULL;
    if (head == NULL) //if empty
    {
        //allocate memory
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;

        //set data
        strncpy(newNode->question, question, MAX_QUESTION_LENGTH);
        strncpy(newNode->answer, answer, MAX_ANSWER_LENGTH);
        newNode->times_correct = times_correct;

        //set list equal to newNode
        head = newNode;
        newNode->next = NULL;

    } else {
        //allocate memory
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;

        //set data
        strncpy(newNode->question, question, MAX_QUESTION_LENGTH);
        strncpy(newNode->answer, answer, MAX_ANSWER_LENGTH);
        newNode->times_correct = times_correct;

        //set list equal to newNode
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}

Node *addNodeB(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, Node * head)
{
    Node *newNode = NULL;
    Node *ptr = head;
    if (head == NULL) //if empty
    {
        //allocate memory
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;

        //set data
        strcpy(newNode->question, question);
        strcpy(newNode->answer, answer);
        newNode->times_correct = times_correct;

        //set list equal to newNode
        head = newNode;
        newNode->next = NULL;

    } else {
        //allocate memory
        newNode = malloc(sizeof(Node));
        if (newNode == NULL) return NULL;

        //set data
        strcpy(newNode->question, question);
        strcpy(newNode->answer, answer);
        newNode->times_correct = times_correct;


        while (ptr->next!= NULL) ptr = ptr->next;
        ptr->next = newNode;
    }
    return head;
}
// insert a node into a position in the list
Node *insertNode(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, int position, Node * head)
{
    Node *ptr = head;

    //check if insertion is needed
    if (position < 0){
        return head;
    }else if (position == 0) {
        head = addNodeF(question,answer,times_correct,head);
        return head;
    }

    //move to insert position
    while (position > 1 && ptr != NULL)
    {
        ptr = ptr->next;
        position--;
    }

    //some error correction
    if (ptr == NULL && position != 0){
        printf("Requested position too far into list\n");
        printf("Failed to insert into list\n");
        return head;
    }

    //on reached position allocate memory. Only created if position is actually reached
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    //insert data into newNode
    newNode->next = ptr->next;
    newNode->times_correct = times_correct;
    strcpy(newNode->question,question);
    strcpy(newNode->answer,answer);

    //insert newNode into list
    ptr->next = newNode;

    return head;
}

// set a node value
Node *setValue(char question[MAX_QUESTION_LENGTH] ,int value, Node *head) {
    Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->question, question) == 0)
        {
            current->times_correct = value;
            return head;
        }
        current = current->next;
    }
    return head;
}
