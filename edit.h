//
// Created by tyroc on 21.10.2018.
//

#ifndef VSTE_EDIT_H
#define VSTE_EDIT_H

#define MAXLEN 255

struct line{
    int nr;
    char* content;

    struct line* prev;
    struct line* next;
};

struct line* first;
struct line* last;

struct line* readFile(char* filename);
#endif //VSTE_EDIT_H
