#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int strength,dexterity,intelligence,healthPoints,manaPoints;
    char name [50];
} Character;

void setCharacterHealthPoints (Character *character, int newHealthPoints);

int getCharacterHealthPoints (Character *character);

void addCharacterHealthPoints (Character *character, int addedHealthPoints);

void setCharacterStrength (Character *character, int newStrength);

int getCharacterStrength (Character *character);

void setCharacterDexterity (Character *character, int newDexterity);

int getCharacterDexterity (Character *character);

void setCharacterIntelligence (Character *character, int newIntelligence);

int getCharacterIntelligence (Character *character);

#endif