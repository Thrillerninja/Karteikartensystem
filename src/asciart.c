//
// Created by rorba on 08.03.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "asciart.h"
#include "node.h" //for constants
#include "file_handling.h"
#include "abfrage.h"

#define MAX_VOCAB 2
#define MAX_TRY_LENGTH 1

extern int number_of_questions_to_ask;
extern int max_tries;

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
        //yes i know there is no case 2, see it as an easteregg
        case 3: //Quit
            system("cls");
            printf(R"EOF(
        +---------------------------------------------------------------------------------------------------+
        |                                                                                                   |
        |                                       ____            _   _                                       |
        |                                      / __ \          (_) | |                                      |
        |                                     | |  | |  _   _   _  | |_                                     |
        |                                     | |  | | | | | | | | | __|                                    |
        |                                     | |__| | | |_| | | | | |_                                     |
        |                                      \___\_\  \__,_| |_|  \__|                                    |
        |                                                                                                   |
        |                                       +---------------------+                                     |
        |                                       |      Continue       |                                     |
        |                                       +---------------------+                                     |
        |                                                                                                   |
        |                                       +---------------------+                                     |
        |                                       |     Main Menu       |                                     |
        |                                       +---------------------+                                     |
        |                                                                                                   |
        |                                       +---------------------+                                     |
        |                                       |       Quit          |                                     |
        |                                       +---------------------+                                     |
        |                                                                                                   |
        +---------------------------------------------------------------------------------------------------+)EOF");
            printf("\n");
            break;

        case 4: //Abfrage
            system("cls");
            static const char* mainMenu = R"EOF(
        +---------------------------------------------------------------------------------------------------+
        |                                                                                                   |
        |                   _  __                                      _                 ___                |
        |                  | |/ /  ___   ___   _ __       __ _   ___  (_)  _ _    __ _  |__ \               |
        |                  | ' <  / -_) / -_) | '_ \     / _` | / _ \ | | | ' \  / _` |   /_/               |
        |                  |_|\_\ \___| \___| | .__/     \__, | \___/ |_| |_||_| \__, |  (_)                |
        |                                     |_|        |___/                   |___/                      |
        |                                                                                                   |
        |                                                                                                   |
        |                                       +---------------------+                                     |
        |                                       |     1-Restart       |                                     |
        |                                       +---------------------+                                     |
        |                                                                                                   |
        |                                       +---------------------+                                     |
        |                                       |    2-Main Menu      |                                     |
        |                                       +---------------------+                                     |
        |                                                                                                   |
        |                                       +---------------------+                                     |
        |                                       |      3-Quit         |                                     |
        |                                       +---------------------+                                     |
        |                                                                                                   |
        +---------------------------------------------------------------------------------------------------+)EOF";
            printf("%s\n",mainMenu);
            break;
    }
}
void printSettings(char path[]) {
    system("cls");
    printf(R"EOF(
        +---------------------------------------------------------------------------------------------------+
        |                         _____          _     _     _                                              |
        |                        / ____|        | |   | |   (_)                                             |
        |                       | (___     ___  | |_  | |_   _   _ __     __ _   ___                        |
        |                        \___ \   / _ \ | __| | __| | | | '_ \   / _` | / __|                       |
        |                        ____) | |  __/ | |_  | |_  | | | | | | | (_| | \__ \                       |
        |                       |_____/   \___|  \__|  \__| |_| |_| |_|  \__, | |___/                       |
        |                                                                 __/ |                             |
        |                                                                |___/                              |
        |     +------------------------------------------------------------------------------------+        |
        |     |1-Vocabulary File Location: %-*s |        |
        |     +------------------------------------------------------------------------------------+        |
        |                                                                                                   |
        |     +------------------------------------+                                                        |
        |     |2-Questions asked every turn:  %*d |                                                        |
        |     +------------------------------------+                                                        |
        |                                                                                                   |
        |     +---------------+                                                                +------+     |
        |     |3-More Options |                                                                |0-Exit|     |
        |     +---------------+                                                                +------+     |
        |                                                                                                   |
        +---------------------------------------------------------------------------------------------------+)EOF",
       MAX_PATH_LENGTH, path,
       4, number_of_questions_to_ask);
    printf("\n");

}

void printSolution(char question[], char answer[], int order_number, int tries,char fail){
    if (fail == 'f'){
        system("cls");
        printf("\x1B[31m" R"EOF(
            +---------------------------------------------------------------------------------------------------+
            |                                                                                                   |
            |  Spielmodus                                                                           Tries: %*d/%*d  |
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
            |                                                                                                   |
            |                                                                                                   |
            +---------------------------------------------------------------------------------------------------+)EOF" "\x1B[0m",
       MAX_TRY_LENGTH, tries,
       MAX_TRY_LENGTH, max_tries,
       MAX_QUESTION_LENGTH, question,
       MAX_ANSWER_LENGTH, answer,
       MAX_VOCAB, order_number,
       MAX_VOCAB, number_of_questions_to_ask);
        _getch(); //waits until user presses any button
    }else {
        system("cls");
        printf("\x1B[32m" R"EOF(
        +---------------------------------------------------------------------------------------------------+
        |                                                                                                   |
        |  Spielmodus                                                                           Tries: %*d/%*d  |
        |                                                                                                   |
        |                                                                                                   |
        |                                                                                                   |
        |                                                                                                   |
        |                                             Correct                                               |
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
        |                                                                                                   |
        |                                                                                                   |
        +---------------------------------------------------------------------------------------------------+)EOF" "\x1B[0m",
       MAX_TRY_LENGTH, tries,
       MAX_TRY_LENGTH, max_tries,
       MAX_QUESTION_LENGTH, question,
       MAX_ANSWER_LENGTH, answer,
       MAX_VOCAB, order_number,
       MAX_VOCAB, number_of_questions_to_ask);
        _getch(); //waits until user presses any button
    }
}

void printQuestion(char question[], char answer[], int order_number, int tries) {
    system("cls");
    printf(R"EOF(
        +---------------------------------------------------------------------------------------------------+
        |                                                                                                   |
        |  Spielmodus                                                                           Tries: %*d/%*d  |
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
        |                                                                                                   |
        |                                                                                                   |
        +---------------------------------------------------------------------------------------------------+)EOF",
   MAX_TRY_LENGTH, tries,
   MAX_TRY_LENGTH, max_tries,
   MAX_QUESTION_LENGTH, question,
   MAX_ANSWER_LENGTH, answer,
   MAX_VOCAB, order_number,
   MAX_VOCAB, number_of_questions_to_ask);
}

int confirmExit(){
    showMenues(3); //Quit screen
    switch (getUserInputNumber()){
        case 1:
            break;
        case 2:
            return 1;
        case 3:
            exit(0);
    }
}