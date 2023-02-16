//
// Created by rorba on 09.02.2023.
//

#ifndef KARTEIKARTENSYSTEM_ADD_NODE_H
#define KARTEIKARTENSYSTEM_ADD_NODE_H

#include "node.h"
Node *addNodeF(int data,Node * head);
Node *addNodeB(int data,Node * head);
Node *insertNode(int data, int position, Node * head);
Node *setValue(int data ,int value, Node *head);
#endif //KARTEIKARTENSYSTEM_ADD_NODE_H
