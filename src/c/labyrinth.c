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

int wegsuchen(lab laby, int y, int x, int ziely, int zielx){

    laby[y][x] = 'X';

    if(x == zielx && y == ziely){
        return 0;
    }
    else{
        return -1;
    }
    
}