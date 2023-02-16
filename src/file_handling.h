//
// Created by rorba on 16.02.2023.
//

#ifndef KARTEIKARTENSYSTEM_FILE_HANDLING_H
#define KARTEIKARTENSYSTEM_FILE_HANDLING_H

#include "node.h"
Node *loadData(char filepath, Node *head);
void saveData(char filepath, Node *head);

#endif //KARTEIKARTENSYSTEM_FILE_HANDLING_H
