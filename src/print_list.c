//
// Created by rorba on 16.02.2023.
//
#include "../../../../../Program Files/JetBrains/CLion 2022.3/bin/mingw/x86_64-w64-mingw32/include/stdio.h"
#include "node.h"

void printList(Node * head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n");
}