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
        if(validatePlayerInput(row, col)){
            field[row][col] = 'O';
            valid = validatePlayerInput(row, col);
        }
    }
}

bool validatePlayerInput(int row, int col){
    if (row < 3 && row >= 0){
        if (col < 3 && col >= 0){
            return true;
        }
    }
    return false;
}

int wasGameWon(char field[3][3]){
    int winner = NOWINNERYET;
    bool fieldFull = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(field[i][j]=='-'){
                fieldFull = false;
            }
        }
    }
    if (fieldFull == true) winner = DRAW; 
    if(field[0][0] == 'O' || field[0][0] == 'X'){
        if (field[0][0] == field[0][1] && field[0][2] == field[0][1]){
            if (field[0][0] == 'O'){
                winner = PLAYER;
            }
            else if (field[0][0] == 'X'){
                winner = COMPUTER;
            }
        }
        if (field[0][0] == field[1][0] && field[1][0] == field[2][0]){
            if (field[0][0] == 'O'){
                winner = PLAYER;
            }
            else if (field[0][0] == 'X'){
                winner = COMPUTER;
            }
        }
        if (field[0][0] == field[1][1] && field[1][1] == field[2][2]){
            if (field[0][0] == 'O'){
                winner = PLAYER;
            }
            else if (field[0][0] == 'X'){
                winner = COMPUTER;
            }
        }
    }
    if(field[2][2] == 'O' || field[2][2] == 'X'){
        if (field[2][2] == field[2][1] && field[2][2] == field[2][0]){
            if (field[2][2] == 'O'){
                winner = PLAYER;
            }
            else if (field[2][2] == 'X'){
                winner = COMPUTER;
            }
        }
        if (field[2][2] == field[1][2] && field[1][2] == field[0][2]){
            if (field[2][2] == 'O'){
                winner = PLAYER;
            }
            else if (field[2][2] == 'X'){
                winner = COMPUTER;
            }
        }
    }
    if(field[1][1] == 'O' || field[1][1] == 'X'){
        if (field[1][1] == field[0][1] && field[0][1] == field[2][1]){
            if (field[1][1] == 'O'){
                winner = PLAYER;
            }
            else if (field[1][1] == 'X'){
                winner = COMPUTER;
            }
        }
        if (field[1][1] == field[1][0] && field[1][0] == field[1][2]){
            if (field[1][1] == 'O'){
                winner = PLAYER;
            }
            else if (field[1][1] == 'X'){
                winner = COMPUTER;
            }
        }
         if (field[2][0] == field[1][1] && field[1][1] == field[0][2]){
            if (field[1][1] == 'O'){
                winner = PLAYER;
            }
            else if (field[1][1] == 'X'){
                winner = COMPUTER;
            }
        }
    }
    return winner;
}

void getComputerInput(char field[3][3]){
    bool symbolSet = false, *pt = &symbolSet;
    fillAlmostFull(field, pt);
    while (!symbolSet){
        int row, col;
        row = rand() % 3;
        col = rand() % 3;
        if (field[row][col] == '-'){
            field[row][col] = 'X';
            symbolSet = true;
        }
    }
}


void fillAlmostFull(char field[3][3], bool* pt) {
    if (field[0][0] == 'X') {
        if (field[0][1] == 'X') {
            if( field[0][2] = '-'){
                field[0][2] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[0][2] == 'X') {
            if( field[0][1] = '-'){
                field[0][1] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[1][0] == 'X') {
            if( field[2][0] = '-'){ 
                field[2][0] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[2][0] == 'X') {
            if( field[1][0] = '-'){ 
                field[1][0] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[1][1] == 'X') {
            if( field[2][2] = '-'){ 
            field[2][2] = 'X';
            *pt = true;
            return;
            }
        }
        else if (field[2][2] == 'X') {
            if( field[1][1] = '-'){ 
            field[1][1] = 'X';
            *pt = true;
            return;
            }
        }
    }
    if (field[0][1] == 'X') {
        if (field[0][0] == 'X') {
            if( field[0][2] = '-'){
                field[0][2] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[0][2] == 'X') {
            if( field[0][0] = '-'){
            field[0][0] = 'X';
            *pt = true;
            return;
            }
        }
        else if (field[1][1] == 'X') {
            if( field[2][1] = '-'){
            field[2][1] = 'X';
            *pt = true;
            return;
            }
        }
        else if (field[2][1] == 'X') {
            if( field[1][1] = '-'){
            field[1][1] = 'X';
            *pt = true;
            return;
            }
        }
    }
    if (field[0][2] == 'X') {
        if (field[0][0] == 'X') {
            field[0][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][1] == 'X') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'X') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][0] == 'X') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'X') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'X') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[1][0] == 'X') {
        if (field[1][1] == 'X') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'X') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'X') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][0] == 'X') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[1][1] == 'X') {
        if (field[1][0] == 'X') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'X') {
            field[1][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][1] == 'X') {
            field[2][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][1] == 'X') {
            field[0][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'X') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'X') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'X') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][0] == 'X') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[1][2] == 'X') {
        if (field[1][0] == 'X') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'X') {
            field[1][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'X') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'X') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[2][0] == 'X') {
        if (field[2][1] == 'X') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'X') {
            field[2][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'X') {
            field[1][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][0] == 'X') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'X') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'X') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[2][1] == 'X') {
        if (field[2][0] == 'X') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'X') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'X') {
            field[0][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][1] == 'X') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[2][2] == 'X') {
        if (field[2][0] == 'X') {
            field[2][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][1] == 'X') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'X') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'X') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'X') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'X') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
    }

    if (field[0][0] == 'O') {
        if (field[0][1] == 'O') {
            if( field[0][2] = '-'){
                field[0][2] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[0][2] == 'O') {
            if( field[0][1] = '-'){
                field[0][1] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[1][0] == 'O') {
            if( field[2][0] = '-'){ 
                field[2][0] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[2][0] == 'O') {
            if( field[1][0] = '-'){ 
                field[1][0] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[1][1] == 'O') {
            if( field[2][2] = '-'){ 
            field[2][2] = 'X';
            *pt = true;
            return;
            }
        }
        else if (field[2][2] == 'O') {
            if( field[1][1] = '-'){ 
            field[1][1] = 'X';
            *pt = true;
            return;
            }
        }
    }
    if (field[0][1] == 'O') {
        if (field[0][0] == 'O') {
            if( field[0][2] = '-'){
                field[0][2] = 'X';
                *pt = true;
                return;
            }
        }
        else if (field[0][2] == 'O') {
            if( field[0][0] = '-'){
            field[0][0] = 'X';
            *pt = true;
            return;
            }
        }
        else if (field[1][1] == 'O') {
            if( field[2][1] = '-'){
            field[2][1] = 'X';
            *pt = true;
            return;
            }
        }
        else if (field[2][1] == 'O') {
            if( field[1][1] = '-'){
            field[1][1] = 'X';
            *pt = true;
            return;
            }
        }
    }
    if (field[0][2] == 'O') {
        if (field[0][0] == 'O') {
            field[0][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][1] == 'O') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'O') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][0] == 'O') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'O') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'O') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[1][0] == 'O') {
        if (field[1][1] == 'O') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'O') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'O') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][0] == 'O') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[1][1] == 'O') {
        if (field[1][0] == 'O') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'O') {
            field[1][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][1] == 'O') {
            field[2][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][1] == 'O') {
            field[0][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'O') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'O') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'O') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][0] == 'O') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[1][2] == 'O') {
        if (field[1][0] == 'O') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'O') {
            field[1][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'O') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'O') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[2][0] == 'O') {
        if (field[2][1] == 'O') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'O') {
            field[2][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'O') {
            field[1][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][0] == 'O') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'O') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'O') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[2][1] == 'O') {
        if (field[2][0] == 'O') {
            field[2][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][2] == 'O') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'O') {
            field[0][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][1] == 'O') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
    }
    if (field[2][2] == 'O') {
        if (field[2][0] == 'O') {
            field[2][1] = 'X';
            *pt = true;
            return;
        }
        else if (field[2][1] == 'O') {
            field[2][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][2] == 'O') {
            field[1][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][2] == 'O') {
            field[0][2] = 'X';
            *pt = true;
            return;
        }
        else if (field[1][1] == 'O') {
            field[0][0] = 'X';
            *pt = true;
            return;
        }
        else if (field[0][0] == 'O') {
            field[1][1] = 'X';
            *pt = true;
            return;
        }
    }
}
