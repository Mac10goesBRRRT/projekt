#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <stdbool.h>

void printPrompt();
void printField(char field[3][3]);
void initField(char field[3][3]);
void getPlayerInput(char field[3][3]);
bool validateUserInput(int row, int col);

#endif