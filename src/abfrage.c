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
#include "devmenu.h"

int getUserInputNumber(){
    while (1) {
        char c = _getch();   // get user input immediately TODO: input only gets registered after `"enter"`
        int value = 0;
        printf("\b");
        return value * 10 + (c - '0'); // converts to number
    }
}

void getUserInputString(char question[], char* answer, int order_number, int tries) {
    while (1) {
        char c = _getch(); // get user input immediately
        printf("\b");

        int len = strlen(answer); // gets length of answer so far
        if (c == '\r') {
            answer[len] = '\0'; // add null terminator to the end of the string
            return;

        } else if (len < MAX_ANSWER_LENGTH) {
            answer[len] = c; // appends the next inputted character
            answer[len + 1] = '\0'; // finishes with the closing character

            printQuestion(question, answer, order_number,tries); // prints inputted char at the right position
        }
    }
}

Node *selectVocabulary(Node *head){/* Low times_correct questioning not working
    Node *current = head;
    int total_weight = 0;
    int weight;

    while (current != NULL){
        if (current->times_correct < 0) {
            // Handle invalid node weight
            printf("Invalid node weight");
            return NULL;
        }
        total_weight += current->times_correct;
        current = current->next;
    }

    // Initialize the random seed
    srand(time(NULL));
    printf("Random counter: %d\n",total_weight);

    // Generate a random number between 1 and sum
    weight = rand() % (total_weight+1);
    printf("Weight %d,%d",weight,total_weight);

    // Loop through the list to find the word that corresponds to the random number
    // The higher the number, the higher the probability of being chosen
    current = head;

    while (current->next != NULL && weight < current->times_correct) {
        weight -= current->times_correct;
        current = current->next;
    }
    return current;*/

    Node *current = head;
    int total_weight = 0;
    int length = 0;
    int weight;

    while (current != NULL){
        if (current->times_correct < 0) {
            // Handle invalid node weight
            printf("Invalid node weight");
            return NULL;
        }
        length++;
        total_weight += current->times_correct;
        current = current->next;
    }

    // Initialize the random seed only once
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    // Generate a random number between 1 and total_weight
    weight = rand() % total_weight;
    printf("Weight %d,%d",weight,length);

    // Loop through the list to find the word that corresponds to the random number
    // The higher the number, the higher the probability of being chosen
    current = head;


    for (int i = 0; i < length; i++) {
        if (weight < current->times_correct) {
            return current;
        }
        weight -= current->times_correct;
        current = current->next;
    }

    // This should never happen
    printf("Failed to select vocabulary\n");
    return NULL;

    /*
    while (current->next != NULL && weight >= 0) {
        weight--;
        current = current->next;
    }
    return current;*/
}

int mainAbfrage() {
    //loads the data
    Node *head = loadData(head); //TODO: live changing
    if (head == NULL) { //check if head has no elements
        printf("No data present");
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

        if (tries <= 3) {
            selected_node->times_correct++; //if correct increment knowledge
            printSolution(selected_node->question, selected_node->answer, i,tries, 's'); // and print solution
        }else{
            printSolution(selected_node->question, selected_node->answer, i, tries, 'f');  //else print solution
        }
    }

    saveData(head);  //save data to file

    showMenues(4);
    switch (getUserInputNumber()){
        case 1:
            mainAbfrage();
            break;
        case 2:
            return 1;
        case 3:
            exit(0);
    }
}


void menuSelectAbfrage(Node *head){
    switch(getUserInputNumber()) {
        case 0:
            confirmExit();
            break;
        case 1: // question new vocabulary
            break;
        case 2: //normal questioning
            system("cls");
            mainAbfrage();
            break;
        case 3: //we´ll see
            break;
        default:
            menuSelectAbfrage(head);
            break;
    }
}

void getFilepath() {
    //extern char filepath[]; //use global filepath TODO: remove
    char answer[MAX_PATH_LENGTH]; //stores the new filepath

    while (1) {
        char c = _getch(); // get user input immediately
        printf("\b");

        int len = strlen(answer); // gets length of answer so far
        if (c == '\r') {
            answer[len] = '\0'; // add null terminator to the end of the string
            //TODO:strcpy(filepath, answer);
            return;

        } else if (len < MAX_ANSWER_LENGTH) {
            answer[len] = c; // appends the next inputted character
            answer[len + 1] = '\0'; // finishes with the closing character

            printSettings(answer, 1); // prints inputted char at the right position
        }
    }
}

int enterSettings(){
    //extern char filepath[];
    int choice;

    printSettings("nothing",1);
    do{
        choice = getUserInputNumber();
        switch(choice) {
            case 0:
                return 1;//return to main menu
            case 1: //enter new filepath
                getFilepath();
                break;
            case 2: //change questions asked every turn
                break;
            case 3: //start dev menu
                devMenu();
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