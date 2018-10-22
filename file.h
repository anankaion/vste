//
// Created by tyroc on 21.10.2018.
//

#ifndef VSTE_EDIT_H
#define VSTE_EDIT_H

#define MAXLEN 255
#define MAXIN 20
#define STDTERM 80

struct line{
    char* content;

    struct line* prev;
    struct line* next;
};

struct line* first;
struct line* last;

void runCommandChain(char** tokens, char filename[]);

void insertNode(char buf[]);
struct line* findLine(int nr);

void readFile(char* filename);
int writeFile(char* filename);

void showFile();
int printLines(int from, int howmany);

int deleteLine(int nr);
int deleteLines(int from, int howmany);

void appendAfterLine(int nr, char* toappend);

#endif //VSTE_EDIT_H
