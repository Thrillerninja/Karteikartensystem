#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "asciart.h"
#include "abfrage.h"
#include "devmenu.h"


void main(int argc, char **argv){
    extern char filepath[];
    strcpy(filepath, "..\\..\\data.json");  //sets standard values for settings
    int number_of_questions_to_ask = 5;

    int exit = 1;

    if(argc > 1){
        devMenu();
    }

    while(1){
        if(exit == 1) { showMenues(0); } // show main menu
        exit = 0;

        int choice = getUserInputNumber(); // asks user to choose

        switch (choice) {
            case 1:
                showMenues(1); //show typeselect window
                do {
                    choice = getUserInputNumber();
                    switch (choice) {
                        case 0:
                            exit = quitScreen();
                            break;
                        case 1: // question new vocabulary
                            break;
                        case 2: //normal questioning
                            system("cls");
                            exit = mainAbfrage(); //TODO: Abfrage Reigenfolge fixen
                            break;
                        case 3: //we´ll see
                            break;
                    }
                } while (exit != 1);
                break;

            case 2:
                exit = Settings(); //show settings
                break;

            case 3:
                exit = quitScreen();
                break;

            default: //stay in main menu if something wrong is selected
                break;
        }
        printf("awdawdawd\n");
    }
}