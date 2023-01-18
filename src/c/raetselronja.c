#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raetselronja.h"
#include "userinput.h"

int input[] = { 17, 19, 23, 29 };

int zahlenraetsel(int input[], int loesung) {
	//gegebene zahlen printne und nach ölösungun fragen
    int eingabe = 0;
    printf("%d %d %d %d\n", input[0], input[1], input[2], input[3]);
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


//Zahlenrätsel : 25,50,54,49,98,102,97,194
//256,289,324,361,