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
    bool valid = false;
    while (!valid){
        printf("Enter the field as row col: ");
        scanf("%d %d", &row, &col);
        row -= 1;
        col -= 1;
        if(validateUserInput(row, col)){
            field[row][col] = 'O';
            valid = validateUserInput(row, col);
        }
    }
}

bool validateUserInput(int row, int col){
    if (row < 3 && row >= 0){
        if (col < 3 && col >= 0){
            return true;
        }
    }
    return false;
}

int wasGameWon(char field[3][3]){
    int winner = NOWINNERYET; 
    if(field[0][0] == 'O'){
        if (field[0][0] == field[0][1] && field[0][2] == field[0][1]){
            winner = PLAYER;
        }
        else if (field[0][0] == field[1][0] && field[1][0] == field[2][0]){
            winner = PLAYER;
        }
        else if (field[0][0] == field[1][1] && field[1][1] == field[2][2]){
            winner = PLAYER;
        }
    }
    else if(field[2][2] == 'O'){
        if (field[2][2] == field[2][1] && field[2][2] == field[2][0]){
            winner = PLAYER;
        }
        else if (field[2][2] == field[1][2] && field[1][2] == field[0][2]){
            winner = PLAYER;
        }
    }
    if(field[1][1] == 'O'){
        if (field[1][1] == field[0][1] && field[0][1] == field[2][1]){
            winner = PLAYER;
        }
        else if (field[1][1] == field[1][0] && field[1][0] == field[1][2]){
            winner = PLAYER;
        }
        else if (field[2][0] == field[1][1] && field[1][1] == field[0][2]){
            winner = PLAYER;
        }
    }
    if(field[0][0] == 'X'){
        if (field[0][0] == field[0][1] && field[0][2] == field[0][1]){
            winner = COMPUTER;
        }
        else if (field[0][0] == field[1][0] && field[1][0] == field[2][0]){
            winner = COMPUTER;
        }
        else if (field[0][0] == field[1][1] && field[1][1] == field[2][2]){
            winner = COMPUTER;
        }
    }
    else if(field[2][2] == 'X'){
        if (field[2][2] == field[2][1] && field[2][2] == field[2][0]){
            winner = COMPUTER;
        }
        else if (field[2][2] == field[1][2] && field[1][2] == field[0][2]){
            winner = COMPUTER;
        }
    }
    if(field[1][1] == 'X'){
        if (field[1][1] == field[0][1] && field[0][1] == field[2][1]){
            winner = COMPUTER;
        }
        else if (field[1][1] == field[1][0] && field[1][0] == field[1][2]){
            winner = COMPUTER;
        }
        else if (field[2][0] == field[1][1] && field[1][1] == field[0][2]){
            winner = COMPUTER;
        }
    }
    return winner;
}