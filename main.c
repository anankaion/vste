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
#include <memory.h>

#include "file.h"
#include "modes/standard.h"

int main(int argc, char* argv[]) {
    char in[MAXIN];

    first = NULL;
    last = NULL;

    char** tokens;

    if (argc > 1){
        readFile(argv[1]);
    } else{
        perror("Too few arguments!\n");
	    exit(EXIT_FAILURE);
    }

    //Help message at beginning
    printf("(Press h for help)\n");

    //Program loop
    while (1){
        printf(">");
        scanf("%s", in);
	    printf("\n");

	    if (in[0] == 'q'){
	        exit(EXIT_SUCCESS);
	    }

        tokens = tokenize(in);
	    runCommandChain(tokens, argv[1]);
    }
}
