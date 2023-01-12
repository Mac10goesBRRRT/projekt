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
    COMPUTERWINSGAME
};


char findWinner(int inputPlayer, int inputComputer);
char getComputerInput();

#endif