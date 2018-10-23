//
// Created by sus on 22.10.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "browse.h"
#include "../file.h"



void runBrowseMode(char** tokens, int* curpos){

    switch (tokens[0][0]){
        case 'd':
            *curpos = (*curpos) + MINSCROLL;
            printLines(*curpos, STDTERM);
            break;

        case 'D':
            *curpos = (*curpos) + MAXSCROLL;
            printLines(*curpos, STDTERM);
            break;

        case 'u':
            *curpos = (*curpos) - MINSCROLL;
            printLines(*curpos, STDTERM);
            break;

        case 'U':
            *curpos = (*curpos) - MAXSCROLL;
            printLines(*curpos, STDTERM);
            break;

        case 'j':
            (*curpos)++;
            printLines(*curpos, STDTERM);
            break;

        case 'k':
            (*curpos)--;
            printLines(*curpos, STDTERM);
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



