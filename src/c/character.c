#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
Character character;

void setCharacterHealthPoints (Character *character, int newHealthPoints){
    character->healthPoints = newHealthPoints;
}