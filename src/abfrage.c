//
// Created by rorba on 17.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "node.h"

#define MAX_VOCAB 2
void menuSettings();
void mainAbfrage(Node *head);
void menuSelectAbfrage(Node *head);
Node *abfrageStart(Node *head);
void printQuestion(char question[], char answer[], int order_number, int max_number);
void userInputChar(char question[],char *answer,int order_number,int number_of_questoins_to_ask);


void showFrame(int x){
    switch(x){
        case 0: //Main Menu
            system("cls");
            printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                          _____    _                              _____                            |
                |                         |  __ \  | |                            | ____|                           |
                |                         | |__) | | |__     __ _   ___    ___    | |__                             |
                |                         |  ___/  | '_ \   / _` | / __|  / _ \   |___ \                            |
                |                         | |      | | | | | (_| | \__ \ |  __/    ___) |                           |
                |                         |_|      |_| |_|  \__,_| |___/  \___|   |____/                            |
                |                                                                                                   |
                |                                                                                                   |
                |                                      +---------------------+                                      |
                |                                      |     1  Start        |                                      |
                |                                      +---------------------+                                      |
                |                                                                                                   |
                |                                      +---------------------+                                      |
                |                                      |     2 Settings      |                                      |
                |                                      +---------------------+                                      |
                |                                                                                                   |
                |                                      +---------------------+                                      |
                |                                      |     3  Quit         |                                      |
                |                                      +---------------------+                                      |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF");
            printf("\n");
            break;

        case 1: //Start
            system("cls");
            printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |               _____                                                      _                        |
                |              / ____|                                                    | |                       |
                |             | |  __    __ _   _ __ ___     ___   _ __ ___     ___     __| |   ___   ___           |
                |             | | |_ |  / _` | | '_ ` _ \   / _ \ | '_ ` _ \   / _ \   / _` |  / _ \ / __|          |
                |             | |__| | | (_| | | | | | | | |  __/ | | | | | | | (_) | | (_| | |  __/ \__ \          |
                |              \_____|  \__,_| |_| |_| |_|  \___| |_| |_| |_|  \___/   \__,_|  \___| |___/          |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |   +---------------------------+   +---------------------------+   +---------------------------+   |
                |   |                           |   |                           |   |                           |   |
                |   |     1-Recently added      |   |        2-Standard         |   |         3-Games           |   |
                |   |                           |   |                           |   |                           |   |
                |   +---------------------------+   +---------------------------+   +---------------------------+   |
                |                                                                                                   |
                |                                                                                                   |
                |   +------+                                                                                        |
                |   |0-Exit|                                                                                        |
                |   +------+                                                                                        |
                +---------------------------------------------------------------------------------------------------+)EOF");
            printf("\n");
            break;

        case 2: //Settings
            system("cls");
            printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                               ___        _      _    _                                            |
                |                              / __> ___ _| |_  _| |_ <_>._ _  ___  ___                             |
                |                              \__ \/ ._> | |    | |  | || ' |/ . |<_-<                             |
                |                              <___/\___. |_|    |_|  |_||_|_|\_. |/__/-                            |
                |                                                             <___'                                 |
                |      Setting 1: on / off               Setting 1: on / off               Setting 1: on / off      |
                |                                                                                                   |
                |      Setting 1: on / off               Setting 1: on / off               Setting 1: on / off      |
                |                                                                                                   |
                |      Setting 1: on / off               Setting 1: on / off               Setting 1: on / off      |
                |                                                                                                   |
                |      Setting 1: on / off               Setting 1: on / off               Setting 1: on / off      |
                |                                                                                                   |
                |      Setting 1: on / off               Setting 1: on / off               Setting 1: on / off      |
                |                                                                                                   |
                |      Setting 1: on / off               Setting 1: on / off               Setting 1: on / off      |
                |                                                                                                   |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF");
            printf("\n");
            break;

        case 3: //Quit
            system("cls");
            printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                          _____    _                              _____                            |
                |                         |  __ \  | |                            | ____|                           |
                |                         | |__) | | |__     __ _   ___    ___    | |__                             |
                |                         |  ___/  | '_ \   / _` | / __|  / _ \   |___ \                            |
                |                         | |      | | | | | (_| | \__ \ |  __/    ___) |                           |
                |                         |_|      |_| |_|  \__,_| |___/  \___|   |____/                            |
                |                                                                                                   |
                |                                                                                                   |
                |                                      +---------------------+                                      |
                |                                      |        Start        |                                      |
                |                                      +---------------------+                                      |
                |                                                                                                   |
                |                                      +---------------------+                                      |
                |                                      |       Settings      |                                      |
                |                                      +---------------------+                                      |
                |                                                                                                   |
                |                                      +---------------------+                                      |
                |                                      |        Quit         |                                      |
                |                                      +---------------------+                                      |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF");
            printf("\n");
            break;

        case 4: //Abfrage
            system("cls");
            printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                                                                                                   |
                |  Spielmodus                                                                            Streek     |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                         +----------------------------------------------+                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Frage: trash trashtrash remove               |                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Antwort: _______________________________     |                          |
                |                         |                                              |                          |
                |                         |                                        1/20  |                          |
                |                         +----------------------------------------------+                          |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+  )EOF");
            printf("\n");
            break;
    }
}

int userInputInt(){
    while (1) {
        char c = _getch();   // get user input immediately TODO: input only gets registered after `"enter"`
        int value = 0;
        printf("\b");
        return value * 10 + (c - '0'); // converts to number
    }
}

void userInputChar(char question[], char* answer, int order_number, int number_of_questions_to_ask) {
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

            printQuestion(question, answer, order_number, number_of_questions_to_ask); // prints inputted char at the right position
        }
    }
}

Node *abfrageStart(Node *head) {
    showFrame(0); // show main menu

    int choice = userInputInt(); // asks user to choose
    switch (choice) {
        case 1:
            showFrame(1); //show typeselect window
            menuSelectAbfrage(head);
            break;

        case 2:
            showFrame(2); //show settings
            break;

        case 3:
            showFrame(3); //Quit screen
            break;

        default: //stay in main menu if something wrong is selected
            break;
    }
    printf("awdawdawd\n");
}

void menuSelectAbfrage(Node *head){
    int choice = userInputInt();
    switch(choice) {
        case 1: // question new vocabulary
            break;
        case 2: //normal questioning
            system("cls");
            mainAbfrage(head);
            break;
        case 3: //we´ll see
            break;
        default:
            menuSelectAbfrage(head);
            break;
    }
}

void printSolution(char question[], char answer[], int order_number, int max_number){
    printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                                                                                                   |
                |  Spielmodus                                                                            Streek     |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                         +----------------------------------------------+                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Frage: )EOF");
    printf("%.*s%*s", MAX_QUESTION_LENGTH, question, MAX_QUESTION_LENGTH-strlen(question), "");
    printf(R"EOF(|                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Antwort: )EOF");
    printf("%.*s%*s", MAX_ANSWER_LENGTH, answer, MAX_ANSWER_LENGTH-strlen(answer), "");
    printf(R"EOF(|                          |
                |                         |                                              |                          |
                |                         |                                       )EOF");
    printf("%.*d/%.*d", MAX_VOCAB, order_number, MAX_VOCAB, max_number);
    printf(R"EOF(  |                          |
                |                         +----------------------------------------------+                          |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF");
    printf("\n");
}

void printQuestion(char question[], char answer[], int order_number, int max_number){
    printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                                                                                                   |
                |  Spielmodus                                                                            Streek     |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                         +----------------------------------------------+                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Frage: )EOF");
    printf("%.*s%*s", MAX_QUESTION_LENGTH, question, MAX_QUESTION_LENGTH-strlen(question), "");
    printf(R"EOF(|                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Antwort: )EOF");
    printf("%.*s%*s", MAX_ANSWER_LENGTH, answer, MAX_ANSWER_LENGTH-strlen(answer), "");
    printf(R"EOF(|                          |
                |                         |                                              |                          |
                |                         |                                       )EOF");
    printf("%.*d/%.*d", MAX_VOCAB, order_number, MAX_VOCAB, max_number);
    printf(R"EOF(  |                          |
                |                         +----------------------------------------------+                          |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF");
    printf("\n");
}

int selectVocabulary(Node *head){
    Node *current = head;
    int counter = 0;
    int position = 0;

    while (current != NULL){
        counter += current->times_correct;
        current = current->next;
    }

    // Initialize the random seed
    srand(time(NULL));
    printf("Random counter: %d\n",counter);

    // Generate a random number between 1 and sum
    int r = rand() % counter+1;

    // Loop through the list to find the word that corresponds to the random number
    // The higher the number, the higher the probability of being chosen
    current = head;

    while (current != NULL) {
        r -= current->times_correct;
        if (r < 0) {
            return position;
        }
        current = current->next;
        position++;
    }
    return position;
}

void mainAbfrage(Node *head) {
    Node *current = head;
    int number_of_questoins_to_ask = 5;
    for (int i = 1; i < number_of_questoins_to_ask+1; i++) {
        //Select variable and show it
        int position = selectVocabulary(head);

        current = head;
        while (position != 0) {
            current = current->next;
            position--;
        }
        printQuestion(current->question, "",i,number_of_questoins_to_ask); //show question
        //End of visualisation

        //Wait for User to enter an answer
        char answer[MAX_ANSWER_LENGTH];
        userInputChar(current->question, answer, i, number_of_questoins_to_ask);
        if (strcmp(answer, current->answer) == 0) { //answer is correct
            printSolution(current->question, current->answer,i,number_of_questoins_to_ask);
            printf("Correct answer");
        } else { //answer is wrong
            i-=1; //restart answering process until correct answer is given
        }

        printf("User chose: %s\n", answer);
    }
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