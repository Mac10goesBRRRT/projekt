#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "labyrinth.h"



int printlabyrinth(lab laby, int hoehe, int breite){
    
    for(int i = 0; i < hoehe; i++){
        for(int j = 0; j < breite; j++){
            printf("%c ", laby[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
return 0;
}

void wegsuchen(lab laby, bool* done, int y, int x, int ziely, int zielx){

    laby[y][x] = 'X';

    if(x == zielx && y == ziely){
        *done = true;
    }
    else{
        if (!*done && y + 1 <= ziely && laby[y+1][x] == '0'){
            wegsuchen(laby, done, y + 1, x, ziely, zielx);
        }
        if (!*done && x + 1 <= zielx && laby[y][x+1] == '0'){
            wegsuchen(laby, done, y, x + 1, ziely, zielx);
        }
    }
}