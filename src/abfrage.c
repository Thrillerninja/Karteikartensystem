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

int getUserInputNumber(){
    while (1) {
        char c = _getch();   // get user input immediately TODO: input only gets registered after `"enter"`
        int value = 0;
        printf("\b");
        return value * 10 + (c - '0'); // converts to number
    }
}

void getUserInputString(char question[], char* answer, int order_number, int number_of_questions_to_ask, int tries, int max_tries) {
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

            printQuestion(question, answer, order_number, number_of_questions_to_ask,tries,max_tries); // prints inputted char at the right position
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
        current = current->next;
    }

    // Initialize the random seed
    srand(time(NULL));
    printf("Random counter: %d\n",length);

    // Generate a random number between 1 and sum
    weight = rand() % length;
    printf("Weight %d,%d",weight,length);

    // Loop through the list to find the word that corresponds to the random number
    // The higher the number, the higher the probability of being chosen
    current = head;

    while (current->next != NULL && weight >= 0) {
        weight--;
        current = current->next;
    }
    return current;
}

void mainAbfrage() {
    //loads the data
    Node *head = loadData("filepath", head);
    if (head == NULL) { //check if head has no elements
        printf("No data present");
    }

    int number_of_questions_to_ask = 1;
    char answer[MAX_ANSWER_LENGTH] = "";
    int tries;

    //questioning of vocabulary
    for (int i = 1; i <= number_of_questions_to_ask; i++) {
        tries = 0;

        //Asks the vocabulary and checks if correct answer is given within the limit set by tries
        Node* selected_node = selectVocabulary(head);
        do {
            memset(answer, 0, sizeof(answer));
            printQuestion(selected_node->question, "", i, number_of_questions_to_ask,tries,3);
            getUserInputString(selected_node->question, answer, i, number_of_questions_to_ask, tries, 3);
            tries++;
        } while (strcmp(answer, selected_node->answer) != 0 && tries <=3);

        if (tries <= 3) {
            selected_node->times_correct++; //if correct increment knowledge
            printSolution(selected_node->question, selected_node->answer, i, number_of_questions_to_ask, tries, 3, "success"); // and print solution
        }else{
            printSolution(selected_node->question, selected_node->answer, i, number_of_questions_to_ask, tries, 3, "failed");  //else print solution
        }
    }

    saveData("filepath",head);  //save data to file

    showMenues(4);
    switch (getUserInputNumber()){
        case 1:
            mainAbfrage();
            break;
        case 2:
            return;
        case 3:
            exit(0);
    }
}

void abfrageMenuSelect() {
    showMenues(0); // show main menu

    int choice = getUserInputNumber(); // asks user to choose

    switch (choice) {
        case 1:
            showMenues(1); //show typeselect window
            do {
                int choice = getUserInputNumber();
                switch (choice) {
                    case 0:
                        quitScreen();
                        break;
                    case 1: // question new vocabulary
                        break;
                    case 2: //normal questioning
                        system("cls");
                        mainAbfrage(); //TODO: Abfrage Reigenfolge fixen
                        return;
                    case 3: //we´ll see
                        break;
                }
            }while (choice != 1 || choice != 2 || choice != 3);
            break;

        case 2:
            Settings(); //show settings
            break;

        case 3:
            quitScreen();
            break;

        default: //stay in main menu if something wrong is selected
            break;
    }
    printf("awdawdawd\n");
}

void menuSelectAbfrage(Node *head){
    switch(getUserInputNumber()) {
        case 0:
            quitScreen();
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

void Settings(){
    int choice;

    printSettings();
    do{
        choice = getUserInputNumber();
        switch(choice) {
            case 0:
                return;
            case 1: //enter new filepath
                break;
            case 2: //change questions asked every turn
                break;
            case 3: //start dev menu
                break;
        }
    }while (choice != 0||choice != 1 || choice != 2 || choice != 3);
    char *filename = "..\\..\\data.json";
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