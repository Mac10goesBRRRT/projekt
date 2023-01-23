#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <stdbool.h>

enum inputOptions{
    ROCK,
    PAPER,
    SCISSORS
};
    
enum roundWinner{
    PLAYERWINSROUND,
    COMPUTERWINSROUND,
    NOWINNER
};

enum gameWinner{
    PLAYERWINSGAME,
    COMPUTERWINSGAME,
    NOTWONYET
};


int findWinner(int inputPlayer, int inputComputer);
int getComputerInput();
int wasGameWon(int roundsToWin, int playerWins, int computerWins);
bool validatePlayerInput(int playerInput);
int getPlayerInput();

#endif