//
// Created by sus on 25.10.18.
//

#ifndef VSTE_MODES_H
#define VSTE_MODES_H

#define MINSCROLL 25
#define MAXSCROLL 50

void runCommandChain(char** tokens, char filename[]);
void runBrowseMode(char** tokens, int* curpos);

int browseMode();
int appendMode(int after);

void showFile();

int deleteLine(int nr);
int deleteLines(int from, int howmany);

void appendAfterLine(int nr, char* toappend);

#endif //VSTE_MODES_H
