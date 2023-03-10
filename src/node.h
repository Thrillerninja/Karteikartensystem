//
// Created by rorba on 09.02.2023.
//

#ifndef KARTEIKARTENSYSTEM_NODE_H
#define KARTEIKARTENSYSTEM_NODE_H

/* Max number of chars in question. This is reasoned by this study: https://arxiv.org/ftp/arxiv/papers/1207/1207.2334.pdf
 * showing that words longer than 30 chars don´t really exist. 8 extra chars are given to be able to differentiate between
 * different answers to a vocable by a pre-/postfix of a shorthand*/
#define MAX_QUESTION_LENGTH 38
#define MAX_ANSWER_LENGTH 36
#define MAX_PATH_LENGTH 55

typedef struct Node {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    int times_correct;
    struct Node *next;
} Node;

#endif //KARTEIKARTENSYSTEM_NODE_H
