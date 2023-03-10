#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <stdbool.h>

enum Winner{
    PLAYER,
    COMPUTER,
    NOWINNERYET,
    DRAW
};

void printPrompt();
void printField(char field[3][3]);
void initField(char field[3][3]);
void getPlayerInput(char field[3][3]);
bool validatePlayerInput(int row, int col);
int wasGameWon(char field[3][3]);
void getComputerInput(char field[3][3]);
void fillAlmostFull(char field[3][3], bool *pt);
int play();
void printWinner(int winner);

#endif