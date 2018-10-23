//
// Created by sus on 22.10.18.
//

#ifndef VSTE_MODE_H
#define VSTE_MODE_H

#define MINSCROLL 25
#define MAXSCROLL 50

struct line* current;

int scrollDownMin(int* curpos);
int scrollDownMax(int* curpos);

int browseMode();

#endif //VSTE_MODE_H
