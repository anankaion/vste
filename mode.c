//
// Created by sus on 22.10.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "mode.h"
#include "file.h"

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

void runBrowseMode(char** tokens, int* curpos){

    switch (tokens[0][0]){
        case 'd':
            scrollDownMin(curpos);
            break;

        case 'D':
            scrollDownMax(curpos);
            break;

        case 'u':

            break;

        case 'U':

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



