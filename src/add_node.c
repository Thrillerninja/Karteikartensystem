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
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    //set data
    strncpy(newNode->question, question, MAX_QUESTION_LENGTH);
    strncpy(newNode->answer, answer, MAX_ANSWER_LENGTH);
    newNode->times_correct = times_correct;

    //set list equal to newNode
    newNode->next = head;

    return newNode;
}

Node *addNodeB(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, Node * head)
{
    Node *newNode = malloc(sizeof(Node)); // create new node
    if (newNode == NULL) {
        return NULL;
    }


    strncpy(newNode->question, question, MAX_QUESTION_LENGTH);
    strncpy(newNode->answer, answer, MAX_ANSWER_LENGTH);
    newNode->times_correct = times_correct;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    //walks to the last element
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    //insert newNode
    current->next = newNode;

    //return the whole list
    return head;
}

// insert a node into a position in the list
Node *insertNode(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, int position, Node * head)
{
    //check if insertion is needed
    if (position < 0){
        return head;
    }else if (position == 0) {
        head = addNodeF(question,answer,times_correct,head);
        return head;
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }

    strncpy(newNode->question, question, MAX_QUESTION_LENGTH);
    strncpy(newNode->answer, answer, MAX_ANSWER_LENGTH);
    newNode->times_correct = times_correct;


    //move to insert position
    Node *current = head;
    while (position > 1 && current != NULL) {
        current = current->next;
        position--;
    }

    //some error correction
    if (current == NULL){
        printf("Requested position too far into list\n");
        printf("Failed to insert into list\n");
        return head;
    }

    //insert data into newNode
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

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
