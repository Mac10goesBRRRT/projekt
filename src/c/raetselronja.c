#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "raetselronja.h"
#include "userinput.h"
#include "randomnumber.h"



int zahlenraetsel(int input[], int loesung, int n) {
	
    int eingabe = 0;
    
    for(int i = 0; i < n; i++){
        printf("%d", input[i]);
        if (i < n -1){
            printf(",");
        }
        printf(" ");
    }
    printf("\n");
    
    printf("Please enter a solution.\n");
    eingabe = userInput(); //hier stand mal scanf,jetzt kommt das in eine Funktion zum testen
    if (eingabe == loesung){
        printf("The answer is right.\n");
        return 1;
    }
    else{
        printf("The answer is wrong.\n");
        return 0;
    }

}

int raetselaufruf() {

    int loesung = 0;
    int n = 0;

   int auswahl = userInput();

    switch (auswahl) {
        case 1: 
            int input1[] = {25, 50, 54, 49, 98, 102, 97, 194}; 
            n = 8;
            loesung = 198;
            zahlenraetsel(input1, loesung, n);
            break;
        case 2:
            int input2[] = {17, 19, 23, 29, 37};
            n = 5;
            loesung = 47;
            zahlenraetsel(input2, loesung, n);
            break;
        case 3:
            int input3[] = {256, 289, 324, 361};
            n = 4;
            loesung = 400;
            zahlenraetsel(input3, loesung, n);
            break;
        default: return -1;
    }

    return auswahl;
}


int armdruecken(int gegner, int spieler){

int differenz = 0;

    if (gegner > spieler){
        differenz = gegner - spieler;
        printf("The opponent is around %d stronger.\n", differenz);
        printf("Defeat.");
        return 0;
    }
    if (gegner < spieler){
        differenz = spieler - gegner;
        printf("The opponent is around %d weaker.\n", differenz);
        printf("Victory.");
        return 1;
    }

}

int blackjack(int spieler, int geber, int janein){

    int lower = 1, upper = 11, count = 1, num = 0, num2 = 0; //num2 nicht notwendig

    srand(time(NULL));

    printf("Wollen Sie das Spiel starten?\nJA(1), NEIN(2)\n");
    janein = userInput();

    while (spieler < 21 && geber < 21) {

        if (janein == 1) {
            for (int i = 1; i <= count; i++) {
                int num = (randnum() % (upper - lower + 1)) + lower;
                printf("Sie haben eine %d bekommen\n", num);
                spieler += num;
                printf("Nun haben Sie: %d\n", spieler);
            }
            for (int i = 1; i <= count; i++) {
                int num = (randnum() % (upper - lower + 1)) + lower;
                printf("Der Geber hat eine %d bekommen\n", num);
                geber += num;
                printf("Nun hat der Geber: %d\n", geber);
            }
            printf("Wollen Sie eine weitere Karte?\nJA(1), NEIN(2)\n");
            janein = userInput();
        }
        else {
            if (spieler <= 0) {
            printf("Auf Wiedersehen");
            return 0;
            break;
            }
            else if (spieler > geber) {
                printf("Spieler hat gewonnen.");
                return 1;
                break;
            }
            else if (spieler < geber) {
                printf("Geber hat gewonnen.");
                return 2;
                break;
            }
        }  
    }
    if (janein == 1 && (spieler >= 21 || geber >= 21)) {
        
        if ((geber > 21 || geber < 21) && spieler == 21) {
            printf("Spieler hat gewonnen.");
            return 1;
        }
        else if (geber == 21 && (spieler > 21 || spieler < 21)) {
            printf("Geber hat gewonnen.");
            return 2;
        }
        else if (geber > 21 && spieler > 21) {
            printf("Verloren");
            return 0;
        }
        else if (geber == spieler && geber == 21) {
            printf("Unentschienden.");
            return 0;
        }
         if (geber > 21 && spieler < 21) {
            printf("Spieler hat gewonnen.");
            return 1;
        }
        if (geber < 21 && spieler > 21) {
            printf("Geber hat gewonnen.");
            return 2;
        }
    }
}

