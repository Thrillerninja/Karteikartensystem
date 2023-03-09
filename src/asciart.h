//
// Created by rorba on 08.03.2023.
//

#ifndef KARTEIKARTENSYSTEM_ASCIART_H
#define KARTEIKARTENSYSTEM_ASCIART_H

void showMenues(int x);
void printSolution(char question[], char answer[], int order_number, int tries, int max_tries,char fail);
void printQuestion(char question[], char answer[], int order_number, int tries, int max_tries);
int quitScreen();
void printSettings(char path[], int questions_per_turn);
#endif //KARTEIKARTENSYSTEM_ASCIART_H
