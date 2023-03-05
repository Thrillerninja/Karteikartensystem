//
// Created by rorba on 16.02.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "add_node.h"

#define BUFFER_SIZE 1024

const char* FILTER_READ = "{\"question\": \"%[^\"]\", \"answer\": \"%[^\"]\", \"times_correct\": %d}\n";
const char* FILTER_WRITE = "{\"question\": \"%s\", \"answer\": \"%s\", \"times_correct\": %d}\n";

char question[MAX_QUESTION_LENGTH] = "test";
char answer[MAX_ANSWER_LENGTH] = "test";

Node *loadData(char filepath[], Node *head){ //TODO: fix questions and answers with spaces
    int times_correct = 0;
    char buffer[BUFFER_SIZE];
    char *filename = "..\\..\\data.json";
    FILE *file;
    errno_t err = fopen_s(&file, filename, "r");

    if (err != 0) {
        printf("Unable to open file '%s'\n", filename);
        printf("Error: %s\n", strerror(errno));
        return NULL;
    }

    Node *ptr = NULL;     //create a new linked list

    fseek(file, 0, SEEK_SET);
    while(feof(file) == 0){
        fscanf_s(file, FILTER_READ, question,MAX_QUESTION_LENGTH, answer,MAX_ANSWER_LENGTH, &times_correct);  //after reading string, the number of allocated bytes has to be given
        ptr = addNodeB(question,answer,times_correct, ptr);
    }

    fclose(file);
    return ptr;
}

void saveData(char filepath[],Node *head){
    char buffer[BUFFER_SIZE];
    char *filename = "..\\..\\data.json";
    FILE *file;
    fopen_s(&file, filename, "w+");

    if (file == NULL) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        printf("Unable to open file '%s'\n", filename);
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