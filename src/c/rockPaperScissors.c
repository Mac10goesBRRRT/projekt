#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "rockPaperScissors.h"

int getComputerInput(){
    int input = rand() % 3;
    return input;
}

int findWinner(int inputPlayer, int inputComputer){
    if (inputPlayer == inputComputer){
        return NOWINNER;
    }
    else if (inputPlayer == ROCK && inputComputer == SCISSORS) {
        return PLAYERWINSROUND;
    }
    else if (inputPlayer == PAPER && inputComputer == ROCK) {
        return PLAYERWINSROUND;
    }
    else if (inputPlayer == SCISSORS && inputComputer == PAPER) {
        return PLAYERWINSROUND;
    }
    else {
        return COMPUTERWINSROUND;
    }
}

int wasGameWon(roundsToWin, playerWins, computerWins){
    int winner;
    if (playerWins == roundsToWin){
        winner = PLAYERWINSGAME;
    }
    else if (computerWins == roundsToWin){
        winner = COMPUTERWINSGAME;
    }
    else {
        winner = NOTWONYET;
    }
    return winner;
}

bool validatePlayerInput(int playerInput){
    bool inputValid;
    if (playerInput == ROCK || playerInput == PAPER || playerInput == SCISSORS){
        inputValid = true;
    }
    else {
        inputValid = false;
    }
    return inputValid;
}