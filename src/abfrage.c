//
// Created by rorba on 17.02.2023.
//

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "node.h"

/* Max number of chars in question. This is reasoned by this study: https://arxiv.org/ftp/arxiv/papers/1207/1207.2334.pdf
 * showing that words longer than 30 chars don´t really exist. 8 extra chars are given to be able to differentiate between
 * different answers to a vocable by a pre-/postfix of a shorthand*/
#define MAX_QUESTION_LENGTH 38
#define MAX_ANSWER_LENGTH 36

void showFrame(int x){
    switch(x){
        case 0: //Main Menu
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

int userInput(){
    while (1) {
        char c = _getch();   // get user input immediately //TODO: input only gets registered after `"enter"`
        int value = 0;
        printf("\b");
        return value * 10 + (c - '0'); // converts to number
    }
}

void menuSettings();
void mainAbfrage();
void menuSelectAbfrage();

Node *abfrageStart(Node *head) {
    showFrame(0); // show main menu

    int choice = userInput(); // asks user to choose
    switch (choice) {
        case 1:
            showFrame(1); //show typeselect window
            menuSelectAbfrage();
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

void menuSelectAbfrage(){
    int choice = userInput();
    switch(choice) {
        case 1: // question new vocabulary
            break;
        case 2: //normal questioning
            mainAbfrage();
            break;
        case 3: //we´ll see
            break;
        default:
            menuSelectAbfrage();
            break;
    }
}

void printQuestion(char question[],char answer[]){
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
                |                         |                                        1/20  |                          |
                |                         +----------------------------------------------+                          |
                |                                                                                                   |
                |  0-Exit                                                                                           |
                |                                                                                                   |
                +---------------------------------------------------------------------------------------------------+)EOF");
    printf("\n");
}

void mainAbfrage(){
    printQuestion("awdawdawdu","rftzguhijtrerhtjzukilo");
}

int searchNode(int data, Node * head) {
    Node *current = head;
    int position = 0;
    while (current!= NULL)
    {
        if (current->data == data)
        {
            return position;
        }
        current = current->next;
        position ++;
    }
    return -1;
}