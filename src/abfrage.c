//
// Created by rorba on 17.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h> //used for random seed

#include "node.h"
#include "file_handling.h"
#include "asciart.h"
#include "dev_menu.h"
#include "add_node.h"
#include "remove_node.h"

//function prototypes
int getUserInputNumber();
void getUserInputString(char question[], char* answer, int order_number, int tries);
Node *selectVocabulary(Node *head);
int mainAbfrage();
int newAbfrage();

//function definitions
int getUserInputNumber(){
    while (1) {
        char input = _getch();   // get user input immediately
        int number = 0;
        printf("\b");
        return number * 10 + (input - '0'); // converts to number
    }
}

void getUserInputString(char question[], char* answer, int order_number, int tries) {
    while (1) {
        char input = _getch(); // get user input immediately
        printf("\b");

        int len = strlen(answer); // gets length of answer so far
        if (input == '\r') {
            answer[len] = '\0'; // add null terminator to the end of the string
            return;

        } else if (len < MAX_ANSWER_LENGTH) {
            answer[len] = input; // appends the next inputted character
            answer[len + 1] = '\0'; // finishes with the closing character

            printQuestion(question, answer, order_number,tries); // prints inputted char at the right position
        }
    }
}

Node *selectVocabulary(Node *head){
    Node *current = head;
    double total_weight = 0;
    int length = 0;

    // Calculate the total weight as the sum of the times_correct inverse
    while (current != NULL) {
        if (current->times_correct < 0) {
            // Handle invalid node weight
            printf("Invalid node weight");
            return NULL;
        }
        length++;
        if (current->times_correct != 0) {
            total_weight += (1.0 / (current->times_correct+0.1));
        }
        current = current->next;
    }

    // Initialize the random seed only once
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    // Generate a random number between 0 and total_weight
    double weight = (double) rand() / RAND_MAX * total_weight;

    // Loop through the list to find the word that corresponds to the random number
    // The higher the number, the higher the probability of being chosen
    current = head;

    while (current != NULL && current->next != NULL) {
        weight -= 1.0/(current->times_correct+0.1);
        if (weight < 0) {
            return current;
        }
        current = current->next;
    }

    if (current->next == NULL || current == NULL ){
        return current;
    }

    // This should never happen
    printf("Failed to select vocabulary\n");
    _getch();
    return NULL;
}

int mainAbfrage() {
    //loads the data
    Node *head = loadData(head);
    if (head == NULL) { //check if head has no elements
        printf("No data present, add vocabulary via the settings or to the data.json file first\nPress any key to return to the main menu");
        _getch();
        return 1;
    }

    char answer[MAX_ANSWER_LENGTH] = "";
    int tries;

    //questioning of vocabulary
    for (int i = 1; i <= number_of_questions_to_ask; i++) {
        tries = 0;

        //Asks the vocabulary and checks if correct answer is given within the limit set by tries
        Node* selected_node = selectVocabulary(head);
        do {
            memset(answer, 0, sizeof(answer));
            printQuestion(selected_node->question, "", i,tries);
            getUserInputString(selected_node->question, answer, i, tries);
            tries++;
        } while (strcmp(answer, selected_node->answer) != 0 && tries <=3);

        if (tries <= max_tries) {
            selected_node->times_correct++; //if correct increment knowledge
            printSolution(selected_node->question, selected_node->answer, i,tries-1, 's'); // and print solution
        }else{
            printSolution(selected_node->question, selected_node->answer, i, tries-1, 'f');  //else print fail
        }
    }
    saveData(head);  //save data to file

    showMenues(4);
    switch (getUserInputNumber()){
        case 1:
            if(mainAbfrage()){
                return 1;
            }
            break;
        case 2:
            return 1;
        case 3:
            exit(0);
    }
}

int newAbfrage() {
    //loads the data
    Node *head = loadData(head);
    if (head == NULL) { //check if head has no elements
        printf("No data present, add vocabulary via the settings or to the data.json file first\nPress any key to return to the main menu");
        _getch();
        return 1;
    }

    char answer[MAX_ANSWER_LENGTH] = "";
    int tries;

    Node *ptr = head;
    Node *filtered = NULL;

    //filter to only have vocabulary with times_correct = 0
    while (ptr->next != NULL){
        if (ptr->times_correct != 0){
            filtered = addNodeB(ptr->question,ptr->answer, ptr->times_correct,filtered);
        }
        ptr = ptr->next;
    }

    //questioning of vocabulary
    for (int i = 1; i <= number_of_questions_to_ask; i++) {
        tries = 0;

        //Asks the vocabulary and checks if correct answer is given within the limit set by tries
        Node* selected_node = selectVocabulary(filtered);
        do {
            memset(answer, 0, sizeof(answer));
            printQuestion(selected_node->question, "", i,tries);
            getUserInputString(selected_node->question, answer, i, tries);
            tries++;
        } while (strcmp(answer, selected_node->answer) != 0 && tries <=3);

        if (tries <= 3) {
            selected_node->times_correct++; //if correct increment knowledge
            printSolution(selected_node->question, selected_node->answer, i,tries, 's'); // and print solution
        }else{
            printSolution(selected_node->question, selected_node->answer, i, tries, 'f');  //else print solution
        }
    }

    //return data to main datastream
    while (filtered != NULL) {
        setValue(filtered->question,filtered->times_correct,head);
        filtered = filtered->next;
    }

    saveData(head);  //save data to file
    emptyList(head); //clear the list

    showMenues(4);
    switch (getUserInputNumber()){
        case 1:
            if (mainAbfrage()){
                return 1;
            }
            break;
        case 2:
            return 1;
        case 3:
            exit(0);
    }
}

void getFilepath() {
    strcpy(filepath,"Enter new filepath and confirm with enter");
    char answer[MAX_PATH_LENGTH] = ""; //stores the new filepath

    printSettings(filepath); //print again with notice filepath

    while (1) {
        char c = _getch(); // get user input immediately
        printf("\b");

        int len = strlen(answer); // gets length of answer so far
        if (c == '\r') {
            answer[len] = '\0'; // add null terminator to the end of the string
            strcpy(filepath, answer);
            return;

        } else if (c == '\b') { // check for backspace key
            if (len > 0) { // make sure there is something to delete
                answer[len-1] = '\0'; // remove last character from answer
                len--;
                printSettings(answer); // print updated answer
            }

        } else if (len < MAX_ANSWER_LENGTH) {
            answer[len] = c; // appends the next inputted character
            answer[len + 1] = '\0'; // finishes with the closing character

            printSettings(answer); // prints inputted char at the right position
        }
    }
}

void changeQuestionAmount(){
    number_of_questions_to_ask = 0;

    printSettings(filepath);
    number_of_questions_to_ask = getUserInputNumber();
    printSettings(filepath);
}

int enterSettings(){
    //extern char filepath[];
    int choice;

    printSettings(filepath);
    do{
        choice = getUserInputNumber();
        switch(choice) {
            case 0:
                return 1;//return to main menu
            case 1: //enter new filepath
                getFilepath();
                break;
            case 2: //change questions asked every turn
                changeQuestionAmount();
                break;
            case 3: //start dev menu
                if (devMenu()){
                    return 1;
                }
                break;
        }
    }while (choice != 0||choice != 1 || choice != 2 || choice != 3);
}

int searchNode(char question[MAX_QUESTION_LENGTH], Node * head) {
    Node *current = head;
    int position = 0;
    while (current!= NULL)
    {
        if (strcmp(current->question,question) == 0)
        {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}