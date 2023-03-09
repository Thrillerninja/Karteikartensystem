#include <stdio.h>
#include <stdlib.h>
#include "asciart.h"
#include "abfrage.h"
#include "devmenu.h"

int enterVocabularyMode();

int main(int argc, char **argv){
    int shouldExit = 1;

    if(argc > 1) devMenu();

    while(1){
        if(shouldExit == 1) showMenues(0); // show main menu
        shouldExit = 0;

        int choice = getUserInputNumber(); // asks user to choose
        switch (choice) {
            case 1: //ask vocabulary
                shouldExit = enterVocabularyMode();
                break;

            case 2: //show settings
                shouldExit = enterSettings();
                break;

            case 3: //shouldExit program after asking again
                shouldExit = confirmExit();
                break;

            default: //stay in main menu if something wrong is selected
                break;
        }
        printf("awdawdawd\n");
    }
    return 0;
}

int enterVocabularyMode() {
    int shouldExit = 1;
    showMenues(1); //show subselection window

    do {
        int choice = getUserInputNumber();
        switch (choice) {
            case 0: //return to the main menu
                shouldExit = 1;
                break;
            case 1: // question new vocabulary //TODO: add questioning
                break;
            case 2: //normal questioning
                system("cls");
                shouldExit = mainAbfrage(); //TODO: Abfrage Reigenfolge fixen
                break;
            case 3: //TODO:we´ll see
                break;
        }
    } while (shouldExit != 1);
}