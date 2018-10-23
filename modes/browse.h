

#ifndef VSTE_MODE_H
#define VSTE_MODE_H

#define MINSCROLL 25
#define MAXSCROLL 50

struct line* current;

int browseMode();

void runBrowseMode(char** tokens, int* curpos);

#endif //VSTE_MODE_H
