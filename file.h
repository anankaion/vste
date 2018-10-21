//
// Created by tyroc on 21.10.2018.
//

#ifndef VSTE_EDIT_H
#define VSTE_EDIT_H

#define MAXLEN 255

struct line{
    char* content;

    struct line* prev;
    struct line* next;
};

struct line* first;
struct line* last;

void readFile(char* filename);
void insertNode(int nr, char buf[]);
void showFile();
struct line* findLine(int nr);
#endif //VSTE_EDIT_H
