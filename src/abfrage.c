//
// Created by rorba on 17.02.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "node.h"
#include "file_handling.h"

#define MAX_VOCAB 2
#define MAX_TRY_LENGTH 1

void mainAbfrage();
void menuSelectAbfrage();
void abfrageMenuSelect();
void printQuestion(char question[], char answer[], int order_number, int max_number,int tries, int max_tries);
void getUserInputString(char question[], char *answer, int order_number, int number_of_questoins_to_ask, int tries, int max_tries);


void showMenues(int x){
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
            static const char* mainMenu =
                    R"EOF(
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
                    +---------------------------------------------------------------------------------------------------+)EOF";

            printf("%s\n",mainMenu);
            break;
    }
}

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

void abfrageMenuSelect() {
    showMenues(0); // show main menu

    int choice = getUserInputNumber(); // asks user to choose

    switch (choice) {
        case 1:
            showMenues(1); //show typeselect window
            do {
                int choice = getUserInputNumber();
                switch (choice) {
                    case 1: // question new vocabulary
                        break;
                    case 2: //normal questioning
                        system("cls");
                        mainAbfrage();
                        break;
                    case 3: //we´ll see
                        break;
                }
            }while (choice != 1 || choice != 2 || choice != 3);
            break;

        case 2:
            showMenues(2); //show settings
            break;

        case 3:
            showMenues(3); //Quit screen
            break;

        default: //stay in main menu if something wrong is selected
            break;
    }
    printf("awdawdawd\n");
}

void menuSelectAbfrage(Node *head){
    int choice = getUserInputNumber();
    switch(choice) {
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

void printSolution(char question[], char answer[], int order_number, int max_number, int tries, int max_tries,char fail[]){
    if (strcmp(fail,"failed")==0){
        system("cls");
        printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                                                                                                   |
                |  Spielmodus                                                                       Tries: %*d/%*d    |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                              Failed                                               |
                |                         +----------------------------------------------+                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Frage: %-*s|                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Antwort: %-*s|                          |
                |                         |                                              |                          |
                |                         |                                        %*d/%*d |                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         +----------------------------------------------+                          |
                |                                    Press any key to continue                                      |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF",
               MAX_TRY_LENGTH, tries,
               MAX_TRY_LENGTH, max_tries,
               MAX_QUESTION_LENGTH, question,
               MAX_ANSWER_LENGTH, answer,
               MAX_VOCAB, order_number,
               MAX_VOCAB, max_number);
        _getch(); //waits until user presses any button
    }else {
        system("cls");
        printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                                                                                                   |
                |  Spielmodus                                                                       Tries: %*d/%*d    |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                         +----------------------------------------------+                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Frage: %-*s|                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Antwort: %-*s|                          |
                |                         |                                              |                          |
                |                         |                                        %*d/%*d |                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         +----------------------------------------------+                          |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF",
               MAX_TRY_LENGTH, tries,
               MAX_TRY_LENGTH, max_tries,
               MAX_QUESTION_LENGTH, question,
               MAX_ANSWER_LENGTH, answer,
               MAX_VOCAB, order_number,
               MAX_VOCAB, max_number);
    }
}

void printQuestion(char question[], char answer[], int order_number, int max_number, int tries, int max_tries) {
    system("cls");
    printf(R"EOF(
                +---------------------------------------------------------------------------------------------------+
                |                                                                                                   |
                |  Spielmodus                                                                       Tries: %*d/%*d    |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                                                                                                   |
                |                         +----------------------------------------------+                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Frage: %-*s|                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         | Antwort: %-*s|                          |
                |                         |                                              |                          |
                |                         |                                        %*d/%*d |                          |
                |                         |                                              |                          |
                |                         |                                              |                          |
                |                         +----------------------------------------------+                          |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF",
           MAX_TRY_LENGTH, tries,
           MAX_TRY_LENGTH, max_tries,
           MAX_QUESTION_LENGTH, question,
           MAX_ANSWER_LENGTH, answer,
           MAX_VOCAB, order_number,
           MAX_VOCAB, max_number);
}

Node *selectVocabulary(Node *head){
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
    return current;
}

void mainAbfrage() {
    Node *head = loadData("filepath", head);
    if (head == NULL) {
        printf("No data present");
    }

    int number_of_questions_to_ask = 5;
    char answer[MAX_ANSWER_LENGTH] = "";
    int tries;

    for (int i = 1; i <= number_of_questions_to_ask; i++) {
        tries = 0;

        //Asks the vocabulary and checks if correct answer is given
        Node* selected_node = selectVocabulary(head);
        do {
            memset(answer, 0, sizeof(answer));
            printQuestion(selected_node->question, "", i, number_of_questions_to_ask,tries,3);
            getUserInputString(selected_node->question, answer, i, number_of_questions_to_ask, tries, 3);
            tries++;
        } while (strcmp(answer, selected_node->answer) != 0 && tries <=3);

        if (tries <= 3) {
            selected_node->times_correct++; // if correct increment knowledge
        }else{
            printSolution(selected_node->question, selected_node->answer, i, number_of_questions_to_ask, tries, 3, "failed");
        }

        //prints the solution
        printSolution(selected_node->question, selected_node->answer, i, number_of_questions_to_ask, tries, 3, "success");
        printf("Correct answer\n");
        printf("User chose: %s\n", answer);
    }
    saveData("filepath",head);
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