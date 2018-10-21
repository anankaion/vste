//
// Created by tyroc on 21.10.2018.
//

#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

#include "file.h"


void insertNode(int nr, char buf[]){
    struct line* l = (struct line*) malloc(sizeof(struct line));
    l->content = malloc(sizeof(char)*strlen(buf));
    strcpy(l->content, buf);

    if (first == NULL){
        l->prev = NULL;
        l->next = NULL;
        first = l;
        last = l;

    } else{
        l->prev = last;
        l->next = NULL;
        last->next = l;
        last = l;
    }
}

void readFile(char* filename){
    FILE *fp = fopen(filename, "r");
    char buf[MAXLEN];

    for (int i = 0; fgets(buf, BUFSIZ, fp); i++){
        insertNode(i, buf);
    }

    fclose(fp);
}

void showFile(){
    struct line* l = first;

    for(int i = 0; l != NULL; i++){
        printf("%d\t%s", i, l->content);
        l = l->next;
    }
}

struct line* findLine(int nr){
    struct line* l = first;

    for (int i = 0; i < nr; ++i) {
        if (l->next != NULL){
            l = l->next;
        } else{
            return NULL;
        }
    }

    return l;
}

int printLines(int from, int howmany){
    struct line* l = first;
    int index = 0;

    while (index < from){
        if(l->next != NULL){
            l = l->next;
        } else{
            return 0;
        }
        index++;
    }

    for (int i = 0; i < howmany; ++i) {
        if (l != NULL){
            printf("%d\t%s", index, l->content);
            l = l->next;
            index++;
        } else{
            return 0;
        }
    }

    return 1;
}

void clear(){
    for (int i = 0; i < STDTERM; ++i) {
        printf("\n");
    }
}

int deleteLine(int nr){
    struct line* l;

    if ((l = findLine(nr))){
        if (l == first){
            l->next->prev = NULL;
        } else if (l == last){
            l->prev->next = NULL;
        } else{
            l->prev->next = l->next;
            l->next->prev = l->prev;
        }

        free(l);
    } else{
        return 0;
    }

    return 1;
}

int deleteLines(int from, int howmany){
    struct line* f;
    struct line* t;

    if ((f = findLine(from))){
        if (f == last){
            return 0;
        }

        t = f;

        for (int i = 0; i < howmany; ++i) {
            if (t->next != NULL){
                t = t->next;

                if (f != t->prev){
                    free(t->prev);
                }
            } else{
                return -1;
            }
        }

        if (f == first){
            first = t;
            t->prev = NULL;
        } else{
            f->prev->next = t;
            t->prev = f->prev;
        }

        free(f);
    } else{
        return -2;
    }

    return 1;
}

void runCommandChain(char** tokens){
    struct line* from;
    int conv;

    switch (tokens[0][0]){
        //show
        case 's':
            if (tokens[1][0] == 'f'){
                showFile();
            } else if (tokens[1][0] == 'l'){
                if ((from = findLine(atoi(tokens[2]))) != NULL){
                    if (tokens[3] == NULL){
                        printf("%s", from->content);
                    } else{
                        if (tokens[3][0] == 's'){
                            if(!printLines(atoi(tokens[2]), 50)){
                                printf("Line exceeding limit\n");
                            }
                        } else{
                            if(!printLines(atoi(tokens[2]), atoi(tokens[3]))){
                                printf("Line exceeding limit\n");
                            }
                        }
                    }
                } else{
                    printf("Line exceeding limit\n");
                }

            } else{
                printf("Wrong argument for show\n");
            }
            break;

        //clear
        case 'c':
            clear();
            break;


        case 'd':
            if (tokens[1][0] == 'l'){
                if (tokens[3] == NULL){
                    deleteLine(atoi(tokens[2]));
                } else{
                    {
                        int r;
                        r = deleteLines(atoi(tokens[2]), atoi(tokens[3]));

                        if (r == 0){
                            printf("This line is the last one. Cannot delete more.\n");
                        } else if(r == -1){
                            printf("Line exceeds limit\n");
                        } else if(r == -2){
                            printf("Line could not be found\n");
                        }
                    }
                }
            }
            break;
    }
}
