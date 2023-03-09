//
// Created by rorba on 16.02.2023.
//

#ifndef KARTEIKARTENSYSTEM_FILE_HANDLING_H
#define KARTEIKARTENSYSTEM_FILE_HANDLING_H

#include "node.h"

//global variables to store settings
extern char filepath[MAX_PATH_LENGTH];
extern int number_of_questions_to_ask;
extern int max_tries;

Node *loadData(Node *head);
void saveData(Node *head);

#endif //KARTEIKARTENSYSTEM_FILE_HANDLING_H
