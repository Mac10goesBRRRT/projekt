#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

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
int wasGameWon(roundsToWin, playerWins, computerWins);

#endif