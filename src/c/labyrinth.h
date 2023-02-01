#ifndef LABYRINTH_H
#define LABYRINTH_H

#define MAXZEILEN 5
#define MAXSPALTEN 5

typedef char lab[MAXZEILEN][MAXSPALTEN];
int printlabyrinth(lab laby, int hoehe, int breite);
int wegsuchen(lab laby, int y, int x, int ziely, int zielx);

#endif