//
// Created by rorba on 16.02.2023.
//
#include "node.h"
#include "file_handling.h"

Node *loadData(char filepath[]){
    FILE *file;
    fopen_s(&file, filepath,"w+");
    if (file == NULL){
        printf("No file found");
        return NULL;
    }


    return loadData;
}