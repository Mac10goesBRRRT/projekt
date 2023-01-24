#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <stdbool.h>

enum InputOptions{
    ROCK,
    PAPER,
    SCISSORS
};
    
enum RoundWinner{
    PLAYERWINSROUND,
    COMPUTERWINSROUND,
    NOWINNER
};

enum GameWinner{
    PLAYERWINSGAME,
    COMPUTERWINSGAME,
    NOTWONYET
};


int findWinner(int playerInput, int computerInput);
int getComputerInput();
int wasGameWon(int roundsToWin, int playerWins, int computerWins);
bool validatePlayerInput(int playerInput);
int getPlayerInput();
int playRockPaperScissors(int rounds);
void printPrompt(int roundsToWin);
void printResult(int playerInput, int computerInput, int roundWinner, int playerWins, int computerWins);

#endif