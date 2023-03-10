//
// Created by rorba on 10.03.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "hangman.h"
#include "node.h"
#include "file_handling.h"
#include "abfrage.h"

void hangman(){
    // Get a word
    Node *head = loadData(head);
    head = selectVocabulary(head);
    char answer[MAX_ANSWER_LENGTH];
    strcpy(answer, head->answer); // copy the answer from the linked list

    int tries = 0;
    int size = strlen(answer);
    //create a mask
    int mask[size];

    // Initialize all elements of the array to 0
    for (int i = 0; i < size; i++) {
        if (answer[i] == ' '){
            mask[i] = 1;
        }else{
            mask[i] = 0;
        }
    }

    char unknown[MAX_ANSWER_LENGTH];
    char user_guess = ' ';

    //Gameplay loop
    int finished = 1;
    while (finished){

        //Print * for empty chars
        for (int i = 0; i < size; i++){
            if (mask[i]){
                unknown[i] = answer[i];
                unknown[i+1] = '\0';
            }else{
                unknown[i] = '*';
                unknown[i+1] = '\0';
            }
        }
        printHangman(unknown,user_guess);

        //let the player guess
        user_guess = _getch();
        printHangman(unknown,user_guess);

        //update the mask to show guessed char
        for(int g = 0;g < size; g++){
            char x = answer[g];
            if (user_guess == x){
                mask[g] = 1;
            }
        }

        //check if won
        finished = 0;
        for (int w = 0; w < size; ++w) {
            if(!mask[w]) {
                finished = 1;
            }
        }
        tries++;
    }
    //quit if correct
    printHangmanSuccess(answer, tries);
    _getch();
}