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

    printPrompt(roundsToWin);
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


void printPrompt(int roundsToWin){
    printf("Hello NAME.\nLet us play a game, shall we? I assume you are familiar with Rock-Paper-Scissors?\nIf not, here are the rules:\nThe first one to win %d rounds wins the game. Rock beats scissors, scissors beats paper and paper beats rock.\nThey are quite simple, even you should understand. Got it?\n", roundsToWin);
}