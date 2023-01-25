#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <stdbool.h>

enum InputOptions{
    ROCK,
    PAPER,
    SCISSORS
};
    
enum RoundWinner{
    PLAYERWINSROUND = 3,
    COMPUTERWINSROUND,
    NOWINNER
};

enum GameWinner{
    PLAYERWINSGAME = 6,
    COMPUTERWINSGAME,
    NOTWONYET
};


int playRockPaperScissors(int rounds);
void printPrompt(int roundsToWin);
void runGame(int *playerWins, int *computerWins);
int getPlayerInput();
bool validatePlayerInput(int playerInput);
int getComputerInput();
int findWinner(int playerInput, int computerInput);
void setScore(int roundwinner, int *playerWins, int *computerWins);
void printResult(int playerInput, int computerInput, int roundWinner, int playerWins, int computerWins);
int wasGameWon(int roundsToWin, int playerWins, int computerWins);
void printWinner(int winner);

#endif