//
// Created by rorba on 16.02.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "add_node.h"

#define BUFFER_SIZE 1024

const char* FILTER_READ = "{\"question\": \"%[^\"]\", \"answer\": \"%[^\"]\", \"times_correct\": %d},\n";
const char* FILTER_WRITE = "{\"question\": \"%s\", \"answer\": \"%s\", \"times_correct\": %d},\n";

char question[MAX_QUESTION_LENGTH];
char answer[MAX_ANSWER_LENGTH];
extern char filepath[];

Node *loadData(Node *head){ //TODO: fix questions and answers with spaces
    int times_correct = 0;
    char buffer[BUFFER_SIZE];
    FILE *file;
    errno_t err = fopen_s(&file, filepath, "r");

    if (err != 0) {
        printf("Unable to open file '%s'\n", filepath);
        printf("Error: %s\n", strerror(errno));
        return NULL;
    }

    Node *ptr = NULL;     //create a new linked list

    fseek(file, 0, SEEK_SET); //go to the start of the file
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) { //get the data
        char question[MAX_QUESTION_LENGTH];
        char answer[MAX_ANSWER_LENGTH];
        sscanf(buffer, FILTER_READ, question, answer, &times_correct); //split the data into question, answer, times_correct
        ptr = addNodeB(question, answer, times_correct, ptr); //append to list
    }

    fclose(file);
    return ptr;
}

void saveData(Node *head){
    char filepath[MAX_PATH_LENGTH];
    FILE *file;
    fopen_s(&file, filepath, "w+");

    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s'\n", filepath);
        printf("Unable to open file '%s'\n", filepath);
        exit(EXIT_FAILURE);
    }

    Node * ptr = head;
    while (ptr != NULL) {
        fprintf_s(file, FILTER_WRITE, ptr->question, ptr->answer, ptr->times_correct);
        ptr = ptr->next;
    }

    fclose(file);
    return;
}