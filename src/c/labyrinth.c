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
            if(laby[i][j] == '1'){
                printf("■ ");
            }

            else{
                printf("%c ", laby[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("How many steps do you need to reach your goal?\n");
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

void labyrinthschritte(lab laby, int hoehe, int breite, int schritte, int versuche){

    int antwort = 0;
    

    antwort = userInput();

    if(antwort == schritte){
        printf("Correct you need %d steps.\n", schritte);

        for(int i = 0; i < hoehe; i++){
            for(int j = 0; j < breite; j++){
                printf("%c ", laby[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else{
        if(versuche != 3){
            printf("Your answer is wrong. Try again.\n");
            versuche = versuche + 1;
            labyrinthschritte(laby, hoehe, breite, schritte, versuche); //if schleife für 3 versuche
        }
        else{
            printf("You lost.\n");
        }
    }  
}

void labyrinthauswahl(int auswahl){

    printf("Bitte wählen Sie ein Labyrinth aus\n");

    switch (auswahl){
    case 1:
        lab laby = {
            {'0', '1', '0', '0', '0', '0'},
            {'0', '1', '0', '1', '1', '0'},
            {'0', '0', '0', '0', '1', '0'},
            {'0', '1', '1', '0', '1', '0'},
            {'0', '1', '0', '0', '1', '0'},
        };
        int hoehe = 5;
        int breite = 6;
        printlabyrinth(laby, hoehe, breite);
        break;
    case 2:
        lab laby2 = {
            {'0', '0', '0', '0', '1', '0', '1', '1', '0'},
            {'1', '0', '1', '0', '0', '1', '1', '1', '0'},
            {'1', '0', '1', '1', '0', '0', '1', '1', '0'},
            {'0', '0', '0', '1', '1', '0', '1', '0', '1'},
            {'0', '1', '0', '1', '0', '0', '1', '0', '1'},
            {'0', '1', '0', '1', '0', '1', '0', '0', '0'},
            {'0', '1', '0', '1', '0', '0', '0', '1', '0'},

        };
        hoehe = 7;
        breite = 9;
        printlabyrinth(laby2, hoehe, breite);
        break;
    
    default:
        break;
    }

}