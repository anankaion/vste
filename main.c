/*
 * vste stands for very simple text editor
 *
 * A very simple project (as the title suggests) to edit text without a trillion shortcuts.
 * It is basically a clone of the ed editor, but since I can not find it anywhere online,
 * I am just going to write it myself
 *
 * by Lukas Schmidt
 */

#include <stdio.h>
#include <stdlib.h>

#include "edit.h"

void printHelp(){
    printf("key\tfunction\targ1\targ2\n");
    printf("------------------------------------------------------\n\n");

    printf("h\thelp\n");
    printf("q\tquit\n");
    printf("s\tshow file\n");
    printf("l\tshow line\tnr\n");
    printf("r\treplace line\tnr\tline\n");
}

int main(int argc, char* argv[]) {
    int c;
    first = NULL;
    last = NULL;

    if (argc > 0){
        readFile(argv[1]);
    } else{
        perror("Too few arguments!\n");
    }

    printf("%s\n%s\n", first->content, last->content);

    //Help message at beginning
    printf("(Press h for help)\n");

    //Program loop
    while (1){
        printf(">");
        c = getchar();

        switch (c){
            case 'h':
                printHelp();
                break;

            case 'q':
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}