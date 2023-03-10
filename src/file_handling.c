//
// Created by rorba on 16.02.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "add_node.h"
#include "file_handling.h"

#define BUFFER_SIZE 1024

const char* FILTER_READ = "{\"question\": \"%[^\"]\", \"answer\": \"%[^\"]\", \"times_correct\": %d}%*[^\\n]\n";
const char* FILTER_WRITE = "{\"question\": \"%s\", \"answer\": \"%s\", \"times_correct\": %d}";

char question[MAX_QUESTION_LENGTH];
char answer[MAX_ANSWER_LENGTH];

//sets standard values for settings
char filepath[] = "..\\..\\data.json";
int number_of_questions_to_ask = 5;
int max_tries = 3;

Node *loadData(Node *head){ //TODO: fix questions and answers with spaces
    int times_correct = 0;
    char buffer[BUFFER_SIZE];
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    Node *ptr = NULL;     //create a new linked list

    FILE *file;
    errno_t err = fopen_s(&file, filepath, "r");

    if (err != 0) {
        printf("Unable to open file '%s'\n", filepath);
        printf("Error: %s\n", strerror(errno));
        return NULL;
    }

    fseek(file, 1, SEEK_SET); //go to the start of the file, skip the [ and start reading
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) { //get the data
        if (buffer[strlen(buffer) - 2] == ']') // if the second to last character in the buffer is ']', we've reached the end of the file
            break;

        sscanf(buffer, FILTER_READ, question, answer, &times_correct); //split the data into question, answer, times_correct
        ptr = addNodeB(question, answer, times_correct, ptr); //append to linked list
    }

    fclose(file);
    return ptr;
}

void saveData(Node *head){
    FILE *file;
    errno_t err = fopen_s(&file, filepath, "w+");

    if (err != 0) {
        printf("Unable to open file '%s'\n", filepath);
        printf("Error: %s\n", strerror(errno));
        return;
    }

    fprintf_s(file, "%c", '['); // add [ at the beginning of the file to comply with json format

    if (file == NULL) { // throws error if file is nonexistent
        fprintf(stderr, "Unable to open file '%s'\n", filepath);
        printf("Unable to open file '%s'\n", filepath);
        exit(EXIT_FAILURE);
    }

    Node * ptr = head;
    while (ptr != NULL) { //loops as long as there is an element in head left and writs the contents to file
        fprintf_s(file, FILTER_WRITE, ptr->question, ptr->answer, ptr->times_correct); //writes the content

        if (ptr->next != NULL) { //code to retain the json format by removing the comma at the end of the line and adding ] if nothing follows
            fprintf_s(file, ",\n");
        }
        ptr = ptr->next;
    }
    fprintf_s(file, "]");
    fclose(file);
}