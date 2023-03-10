#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "rockPaperScissors.h"

int playRockPaperScissors(int rounds){
    int roundsToWin = (rounds/2)+1;
    int winner = NOTWONYET;
    int playerWins = 0, computerWins = 0, *playerPt = &playerWins, *computerPt = &computerWins;

    printPrompt(roundsToWin);
    while (winner == NOTWONYET){
        runGame(playerPt, computerPt);
        winner = wasGameWon(roundsToWin, playerWins, computerWins);
    }
    printWinner(winner);
    return winner;
}


void printPrompt(int roundsToWin){
    printf("Hello NAME.\nLet us play a game, shall we? I assume you are familiar with Rock-Paper-Scissors?\nIf not, here are the rules:\nThe first one to win %d rounds wins the game. Rock beats scissors, scissors beats paper and paper beats rock.\nThey are quite simple, even you should understand. Got it?\n", roundsToWin);
}


void runGame(int *playerWins, int *computerWins){
    int computerInput, playerInput;
    int roundwinner = NOWINNER;
    
    playerInput = getPlayerInput();
    computerInput = getComputerInput();
    roundwinner = findWinner(playerInput, computerInput);
    setScore(roundwinner, playerWins, computerWins);
    printResult(playerInput, computerInput, roundwinner, *playerWins, *computerWins);
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
    srand(time(0));
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


void setScore(int roundwinner, int *playerWins, int *computerWins){
    if (roundwinner == PLAYERWINSROUND){
        *playerWins += 1;
    }
    else if (roundwinner == COMPUTERWINSROUND){
        *computerWins += 1;
    }
}


void printResult(int playerInput, int computerInput, int roundWinner, int playerWins, int computerWins){
    switch (playerInput){
        case ROCK: printf("So you chose rock.\n"); break;
        case PAPER: printf("So you chose paper.\n"); break;
        case SCISSORS: printf("So you chose scissors.\n"); break;
    }

    switch (roundWinner)
    {
        case PLAYERWINSROUND: printf("Seems you win this round, I chose "); break;
        case COMPUTERWINSROUND: printf("Too bad for you. I win this one, I chose "); break;
        case NOWINNER: printf("Looks like it's a draw, I also chose "); break;
    }

    switch (computerInput)
    {
        case ROCK: printf("rock.\n"); break;
        case PAPER: printf("paper.\n"); break;
        case SCISSORS: printf("scissors.\n"); break;
    }

    printf("With this, you are at %d wins and I am at %d.\n", playerWins, computerWins);
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


void printWinner(int winner){
    if (winner == PLAYERWINSGAME){
        printf("Damn you, you beat me! You actually won! Oh well, I stand by my word. You may pass.\n");
    }
    else if (winner == COMPUTERWINSGAME){
        printf("Oh poor you, seems like I won. You're gomma have to try again. Do better next time.\n");
    }
}