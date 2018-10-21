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

void insertNode(int nr, char buf[]);
void runCommandChain(char** tokens);

void readFile(char* filename);
void showFile();

struct line* findLine(int nr);
int printLines(int from, int howmany);

int deleteLine(int nr);
int deleteLines(int from, int howmany);

#endif //VSTE_EDIT_H
