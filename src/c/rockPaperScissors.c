#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rockPaperScissors.h"

char getComputerInput(){
    int input = rand() % 3;
    return input;
}

char findWinner(int inputPlayer, int inputComputer){
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

char wasGameWon(roundsToWin, playerWins, computerWins){
    char winner;
    if (playerWins == roundsToWin){
        winner = PLAYERWINSGAME;
    }
    return winner;
}

