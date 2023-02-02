#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "labyrinth.h"
#include "userinput.h"



int printlabyrinth(lab laby, int hoehe, int breite){
    
    for(int i = 0; i < hoehe; i++){
        for(int j = 0; j < breite; j++){
            printf("%c ", laby[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Wie viele Schritte brauchen Sie bis zum Ziel?\n");
    printf("\n");

return 0;
}


void wegsuchen(lab laby, bool* done, int y, int x, int ziely, int zielx){

    laby[y][x] = MARKIERT;


    if(x == zielx && y == ziely){
        *done = true;
    }
    else{
        if (!*done && y + 1 <= ziely && laby[y+1][x] == WEG){
            wegsuchen(laby, done, y + 1, x, ziely, zielx);
        }
        if (!*done && x + 1 <= zielx && laby[y][x+1] == WEG){
            wegsuchen(laby, done, y, x + 1, ziely, zielx);
        }
        if (!*done && y - 1 >= 0 && laby[y-1][x] == WEG){ // oben
            wegsuchen(laby, done, y - 1, x, ziely, zielx);
        }
        if (!*done && x - 1 >= 0 && laby[y][x-1] == WEG){ // links
            wegsuchen(laby, done, y, x - 1, ziely, zielx);
        }
        if (!*done){
            laby[y][x] = WEG;
        }
    }
}

void labyrinthschritte(lab laby, int hoehe, int breite, int schritte){

    int antwort = 0;

    antwort = 14;

    if(antwort == schritte){
        printf("Richtig, Sie brauchen %d Schritte.\n", schritte);

        for(int i = 0; i < hoehe; i++){
            for(int j = 0; j < breite; j++){
                printf("%c ", laby[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    


    
}