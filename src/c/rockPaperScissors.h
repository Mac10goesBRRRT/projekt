#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

enum inputOptions{
    ROCK,
    PAPER,
    SCISSORS
};
    
enum roundWinner{
    PLAYERWINSROUND = 'p',
    COMPUTERWINSROUND = 'c',
    NOWINNER = 'n'
};


char findWinner(int inputPlayer, int inputComputer);

#endif