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

int calculateStatIncrease (Character *character, int amount) {
    return character->level*amount;
}

void setCharacterMaxHealthPoints (Character *character, int newMaxHealthPoints){
    character->maxHealthPoints = newMaxHealthPoints;
}

int getCharacterMaxHealthPoints (Character *character){
    return character->maxHealthPoints;
}

void setCharacterAttack (Character *character, int newAttack){
    character->attack = newAttack;
}

int getCharacterAttack (Character *character){
    return character->attack;
}

void setCharacterArmor (Character *character, int newArmor){
    character->armor = newArmor;
}

int getCharacterArmor (Character *character){
    return character->armor;
}

void setCharacterGold (Character *character, int newGold){
    character->gold = newGold;
}

int getCharacterGold (Character *character){
    return character->gold;
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
    default:
        break;
    }
}
void levelUp (Character *character) {
   if (getCharacterExp(character) > getCharacterMaxExp(character)) {
        increaseStat(character,LEVEL,1);
        setCharacterExp(character,getCharacterExp(character)-getCharacterMaxExp(character));
   }
}