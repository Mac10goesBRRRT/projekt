#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ticTacToe.h"


int something(int a){
    return a;
}

void printPrompt(){
    printf("Let's play Tic Tac Toe. You will use O, I will use X.\nJust enter the number of the field you choose as row col.\nYou start.\n");
}

void printField(char field[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d", field[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
    }
}