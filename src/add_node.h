//
// Created by rorba on 09.02.2023.
//

#ifndef KARTEIKARTENSYSTEM_ADD_NODE_H
#define KARTEIKARTENSYSTEM_ADD_NODE_H

#include "node.h"
Node *addNodeF(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, Node * head);
Node *addNodeB(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, Node * head);
Node *insertNode(char question[MAX_QUESTION_LENGTH],char answer[MAX_ANSWER_LENGTH],int times_correct, int position, Node * head);
Node *setValue(int times_correct ,int value, Node *head);
#endif //KARTEIKARTENSYSTEM_ADD_NODE_H
