#include <stdio.h>
#include <stdlib.h>
#include "asciart.h"
#include "abfrage.h"
#include "dev_menu.h"
#include "hangman.h"

int enterVocabularyMode();

int main(int argc, char **argv){
    int shouldExit = 1;

    if(argc > 1) devMenu();

    while(1){
        if(shouldExit == 1) showMenues(0); // show main menu with style 0
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
    }
    return 0;
}

int enterVocabularyMode() {
    int shouldExit = 1;
    showMenues(1); //show subselection window

    while(1) {
        int choice = getUserInputNumber();
        switch (choice) {
            case 0: //return to the main menu
                return 1;
            case 1: // question new vocabulary
                system("cls");
                if (newAbfrage()) return 1;
                break;
            case 2: //normal questioning
                system("cls");
                if (mainAbfrage()) return 1;
                break;
            case 3:  //start hangman
                system("cls");
                hangman();
                return 1;
        }
    }
}