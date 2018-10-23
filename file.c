
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

#include "file.h"
#include "modes/browse.h"

char** tokenize(char in[]){
    char **tokens;

    tokens[0] = strtok(in, ";");

    for (int i = 1; (tokens[i] = strtok(NULL, ";")) != NULL; ++i);

    return tokens;
}

void insertNode(char buf[]){
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
        insertNode(buf);
    }

    fclose(fp);
}

int writeFile(char* filename){
    FILE *fp;
    struct line* l = first;

    if ((fp = fopen(filename, "w"))){
        while (l != NULL){
            if (fputs(l->content, fp)){
                l = l->next;
            } else{
                fclose(fp);
                return 0;
            }
        }
    } else{
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 1;
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
    for (int i = 0; i < STDTERM+1; ++i) {
        printf("\n");
    }
}