#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

enum inputOptions{
        ROCK = 1,
        PAPER = 2,
        SCISSORS = 3
    };
    
char findWinner(int inputPlayer, int inputComputer);

#endif