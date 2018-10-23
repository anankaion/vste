#include <stdio.h>

#include "append.h"
#include "standard.h"
#include "../file.h"

int appendMode(int after){
    char in[MAXLEN];

    while (1){
        printf("%%");
        scanf("%s", in);
        printf("\n");

        if (in[0] == 'q'){
            return 0;
        }

        appendAfterLine(after, in);
        after++;
    }
}