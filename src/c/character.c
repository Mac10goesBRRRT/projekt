#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
Character character;

void setCharacterHealthPoints (Character *character, int newHealthPoints){
    character->healthPoints = newHealthPoints;
}

int getCharacterHealthPoints (Character *character) {
    return character->healthPoints;
}

void setCharacterStrength(Character *character, int newStrength)
{
   character->strength = newStrength;
}
