//
// Created by tyroc on 21.10.2018.
//

#ifndef VSTE_EDIT_H
#define VSTE_EDIT_H

#define MAXLEN 255
#define MAXIN 20
#define STDTERM 50

struct line{
    char* content;

    struct line* prev;
    struct line* next;
};

struct line* first;
struct line* last;

void insertNode(char buf[]);
char** tokenize(char in[]);
void clear();

struct line* findLine(int nr);
int printLines(int from, int howmany);

void readFile(char* filename);
int writeFile(char* filename);

#endif //VSTE_EDIT_H
