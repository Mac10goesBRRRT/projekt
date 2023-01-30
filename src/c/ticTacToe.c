#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ticTacToe.h"


void printPrompt(){
    printf("Let's play Tic Tac Toe. You will use O, I will use X.\nJust enter the number of the field you choose as row col.\nYou start.\n");
}

void printField(char field[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c", field[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
    }
}

void initField(char field[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = '-';
        }
    }
}

void getPlayerInput(char field[3][3]){
    int row, col;
    printf("Enter the field as row col: ");
    scanf("%d %d", &row, &col);
    row -= 1;
    col -= 1;
    field[row][col] = 'O';
}

bool validateUserInput(int row, int col){
    if (row < 3 && row >= 0){
        if (col < 3 && col >= 0){
            return true;
        }
    }
    return false;
}