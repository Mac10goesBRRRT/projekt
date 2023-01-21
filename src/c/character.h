#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int strength,dexterity,intelligence,healthPoints,manaPoints,level,exp,maxExp,statPoints;
    char name [50];
} Character;

enum {
    STRENGTH = 1, DEXTERITY = 2, INTELLIGENCE = 3, HEALTHPOINTS = 4, MANAPOINTS = 5, LEVEL = 6, EXP = 7, MAXEXP = 8,STATPOINTS = 9
};

void setCharacterHealthPoints (Character *character, int newHealthPoints);

int getCharacterHealthPoints (Character *character);

void setCharacterStrength (Character *character, int newStrength);

int getCharacterStrength (Character *character);

void setCharacterDexterity (Character *character, int newDexterity);

int getCharacterDexterity (Character *character);

void setCharacterIntelligence (Character *character, int newIntelligence);

int getCharacterIntelligence (Character *character);

void setCharacterLevel (Character *character, int newLevel);

int getCharacterLevel (Character *character);

void setCharacterExp (Character *character, int newExp);

int getCharacterExp (Character *character);

void setCharacterMaxExp (Character *character, int newMaxExp);

int getCharacterMaxExp (Character *character);

void setCharacterStatPoints (Character *character, int newStatPoints);

int getCharacterStatPoints (Character *character);

void increaseStat (Character *character, int stat, int amount);

int calculateStatIncrease (Character *character, int amount);

void levelUp (Character *character);
#endif