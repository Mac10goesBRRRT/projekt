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


char findWinner(int inputPlayer, int inputComputer);

#endif