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
    strcpy(answer, head->answer);

    //create a mask
    int mask[strlen(answer)];
    memset(mask, 0, strlen(answer));

    //Gameplay loop
    int finished = 1;
    while (finished){
        //Print - for empty chars
        printf("The word is: ");
        for (int i = 0; i < strlen(answer); i++){
            if (mask[i]){
                printf("$c",answer[i]);
            }else{
                printf("*");
            }
        }
        printf("\n");

        //let the player guess
        printf("Guess the next character\n");
        char user_guess = _getch();

        //update the mask to show guessed char
        for(int g = 0;g < strlen(answer); g++){
            char x = answer[g];
            if (user_guess == x){
                mask[g] = 1;
            }
        }

        //check if wo
        finished = 0;
        for (int w = 0; w < strlen(answer); ++w) {
            if(!mask[w]) finished = 1;
            break;
        }

    }
    //quit if correct
    printf("You guessed correctly, the word is: %s.\nPress any Key to return to the main menu",answer);
    _getch();
}