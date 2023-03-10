#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdbool.h>

#define MAXZEILEN 10
#define MAXSPALTEN 10
#define WEG '0'
#define MARKIERT 'X'
#define MAUER '1'

typedef char lab[MAXZEILEN][MAXSPALTEN];
int printlabyrinth(lab laby, int hoehe, int breite);
void wegsuchen(lab laby, bool* done, int y, int x, int ziely, int zielx);
void labyrinthschritte(lab laby, int hoehe, int breite, int schritte, int versuche);
void labyrinthauswahl(int auswahl);
#endif