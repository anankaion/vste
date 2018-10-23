//
// Created by sus on 23.10.18.
//

#ifndef VSTE_STANDARD_H
#define VSTE_STANDARD_H

void runCommandChain(char** tokens, char filename[]);

void showFile();

int deleteLine(int nr);
int deleteLines(int from, int howmany);

void appendAfterLine(int nr, char* toappend);

#endif //VSTE_STANDARD_H
