#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "rockPaperScissors.h"

int playRockPaperScissors(int rounds){
    int playerWins = 0, computerWins = 0;
    int roundsToWin = (rounds/2)+1;
    int computerInput, playerInput;
    int roundwinner = NOWINNER;
    int winner = NOTWONYET;

    printf("Lets play a game\n");
    while (winner == NOTWONYET){
        playerInput = getPlayerInput();
        computerInput = getComputerInput();
        roundwinner = findWinner(playerInput, computerInput);
        if (roundwinner == PLAYERWINSROUND){
            playerWins += 1;
        }
        else if (roundwinner == COMPUTERWINSROUND){
            computerWins += 1;
        }
        winner = wasGameWon(roundsToWin, playerWins, computerWins);
        printf("Something happened\n");
    }
    printf("Someone won\n");
}


int getPlayerInput(){
    bool inputValid = false;
    int playerInput;
    while(!inputValid){
        printf("Enter your choice:\n1 for Rock\n2 for Paper\n3 for Scissors\n");
        scanf("%d", &playerInput);
        playerInput -= 1;
        inputValid = validatePlayerInput(playerInput);
    }
    return playerInput;
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


int getComputerInput(){
    int input = rand() % 3;
    return input;
}


int findWinner(int playerInput, int computerInput){
    if (playerInput == computerInput){
        return NOWINNER;
    }
    else if (playerInput == ROCK && computerInput == SCISSORS) {
        return PLAYERWINSROUND;
    }
    else if (playerInput == PAPER && computerInput == ROCK) {
        return PLAYERWINSROUND;
    }
    else if (playerInput == SCISSORS && computerInput == PAPER) {
        return PLAYERWINSROUND;
    }
    else {
        return COMPUTERWINSROUND;
    }
}


int wasGameWon(int roundsToWin, int playerWins, int computerWins){
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