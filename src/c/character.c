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

void setCharacterStrength (Character *character, int newStrength) {
   character->strength = newStrength;
}

int getCharacterStrength (Character *character) {
    return character->strength;
}

void setCharacterDexterity (Character *character, int newDexterity) {
    character->dexterity = newDexterity;
}

int getCharacterDexterity (Character *character) {
    return character->dexterity;
}

void setCharacterIntelligence (Character *character, int newIntelligence) {
    character->intelligence = newIntelligence;
}

int getCharacterIntelligence (Character *character) {
    return character->intelligence;
}

void setCharacterLevel (Character *character, int newLevel) {
    character->level = newLevel;
}

int getCharacterLevel (Character *character) {
    return character->level;
}


void increaseStat (Character *character, int stat, int amount) {
    switch (stat)
    {
    case 1:        
        character->strength += amount;break;
    case 2:
        character->dexterity += amount;break;
    case 3:
        character->intelligence += amount;break;
    case 4:
        character->healthPoints += amount;break;
    case 5:
        character->manaPoints += amount;break;
    default:
        break;
    }
}
