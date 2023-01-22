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

void setCharacterExp (Character *character, int newExp) {
    character->exp = newExp;
}

int getCharacterExp (Character *character) {
    return character->exp;
}

void setCharacterMaxExp (Character *character, int newMaxExp) {
    character->maxExp = newMaxExp;
}

int getCharacterMaxExp (Character *character) {
    return character->maxExp;
}

void setCharacterStatPoints (Character *character, int newStatPoints) {
    character->statPoints = newStatPoints;
}

int getCharacterStatPoints (Character *character) {
    return character->statPoints;
}

int calculateStatIncrease (Character *character) {
    if(character->statPoints > 0) {
        setCharacterStatPoints(character,getCharacterStatPoints(character)-1);
        return 5;
    } else {
        return 0;
    }
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
    case 6:
        character->level += amount;break;
    case 7:
        character->exp += amount;break;
    case 8:
        character->maxExp += amount;break;
    case 9:
        character->statPoints += amount;break;
    default:
        break;
    }
}
void levelUp (Character *character) {
   if (getCharacterExp(character) > getCharacterMaxExp(character)) {
        increaseStat(character,LEVEL,1);
        setCharacterExp(character,getCharacterExp(character)-getCharacterMaxExp(character));
   }else {
        printf("You don't have enough Exp to Level Up.\n");
    }
}