#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "raetselronja.h"
#include "userinput.h"
#include "randomnumber.h"



int zahlenraetsel(int input[], int loesung, int n) {
	//gegebene zahlen printne und nach ölösungun fragen
    int eingabe = 0;
    
    for(int i = 0; i < n; i++){
        printf("%d", input[i]);
        if (i < n -1){
            printf(",");
        }
        printf(" ");
    }
    printf("\n");
    
    printf("Bitte geben Sie die Loesung ein.\n");
    eingabe = userInput(); //hier stand mal scanf,jetzt kommt das in eine Funktion zum testen
    if (eingabe == loesung){
        return 1;
        printf("Die Antwort ist richtig.\n");
    }
    else{
        return 0;
        printf("Die Antwort ist falsch.\n");
    }

}

int raetselaufruf() {

    int loesung = 0;
    int n = 0;
    //int auswahl = 1;

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
        //default: return -1;
    }

    return auswahl;
}


int armdruecken(int gegner, int spieler){

int differenz = 0;

if (gegner > spieler){
    differenz = gegner - spieler;
    printf("Der Gegner ist um %d stärker\n", differenz);
    printf("Niederlage");
    return 0;
}
if (gegner < spieler){
    differenz = spieler - gegner;
    printf("Der Gegner ist um %d schwächer\n", differenz);
    printf("Sieg");
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


//geber größer 21 spieler kleinr 21
// einer über 21 der andere drunter


