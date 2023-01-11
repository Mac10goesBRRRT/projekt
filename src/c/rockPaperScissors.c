#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rockPaperScissors.h"


char findWinner(int inputPlayer, int inputComputer){
    if (inputPlayer == inputComputer){
        return 'n';
    }
    else if (inputPlayer == ROCK){
        if (inputComputer == SCISSORS){
            return 'p';
        }
    }
    else if (inputPlayer == PAPER){
        if (inputComputer == ROCK){
            return 'p';
        }
    }
    else if (inputPlayer == SCISSORS){
        if (inputComputer == PAPER){
            return 'p';
        }
    }
}