#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdbool.h>

#define MAXZEILEN 5
#define MAXSPALTEN 5

typedef char lab[MAXZEILEN][MAXSPALTEN];
int printlabyrinth(lab laby, int hoehe, int breite);
void wegsuchen(lab laby, bool* done, int y, int x, int ziely, int zielx);

#endif