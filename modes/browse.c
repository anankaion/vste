//
// Created by sus on 22.10.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "browse.h"
#include "../file.h"

int scrollDownMin(int* curpos){
    for (int i = 0; i < MINSCROLL; ++i) {
        printf("%d\t%s",*curpos , current->content);

        if (current->next != NULL){
            current = current->next;
            (*curpos)++;
        } else{
            return 0;
        }
    }

    return 1;
}

int scrollDownMax(int* curpos){
    for (int i = 0; i < MAXSCROLL; ++i) {
        printf("%d\t%s",*curpos , current->content);

        if (current->next != NULL){
            current = current->next;
            (*curpos)++;
        } else{
            return 0;
        }
    }

    return 1;
}

int scrollUpMin(int* curpos){
    for (int i = 0; i < MINSCROLL; ++i) {
        if (current->prev != NULL){
            current = current->prev;
            (*curpos)--;
        } else{
            return 0;
        }
    }

    printLines(*curpos, MINSCROLL);

    return 1;
}

int scrollUpMax(int* curpos){
    for (int i = 0; i < MAXSCROLL; ++i) {
        if (current->prev != NULL){
            current = current->prev;
            (*curpos)--;
        } else{
            return 0;
        }
    }

    printLines(*curpos, MAXSCROLL);

    return 1;
}

void runBrowseMode(char** tokens, int* curpos){

    switch (tokens[0][0]){
        case 'd':
            scrollDownMin(curpos);
            break;

        case 'D':
            scrollDownMax(curpos);
            break;

        case 'u':
            scrollUpMin(curpos);
            break;

        case 'U':
            scrollUpMax(curpos);
            break;

        case 'c':
            clear();
            break;
    }
}

int browseMode(){
    char in[MAXIN];
    char** tokens;

    current = first;
    int curpos = 0;

    while (1){
        printf("$");
        scanf("%s", in);
        printf("\n");

        if (in[0] == 'q'){
            return 0;
        }

        tokens = tokenize(in);
        runBrowseMode(tokens, &curpos);
    }
}



