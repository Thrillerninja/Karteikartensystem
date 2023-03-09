//
// Created by rorba on 17.02.2023.
//

#ifndef KARTEIKARTENSYSTEM_ABFRAGE_H
#define KARTEIKARTENSYSTEM_ABFRAGE_H

#include "node.h"

int getUserInputNumber();
void getUserInputString(char question[], char* answer, int order_number, int tries);
Node *selectVocabulary(Node *head);
int mainAbfrage();
void abfrageMenuSelect();
void menuSelectAbfrage(Node *head);
int enterSettings();
int searchNode(char question[MAX_QUESTION_LENGTH], Node * head);

#endif //KARTEIKARTENSYSTEM_ABFRAGE_H
