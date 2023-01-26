#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int strength,dexterity,intelligence,healthPoints,manaPoints,level,exp,maxExp;
    int armor, weaponDamage, maxHealthPoints, maxManaPoints;
    int items[10];
    char name [50];
} Character;

enum {
    STRENGTH = 1, DEXTERITY = 2, INTELLIGENCE = 3, HEALTHPOINTS = 4, MANAPOINTS = 5, LEVEL = 6, EXP = 7, MAXEXP = 8
};
enum {
    SWORD = 1, BOW = 2, STAFF = 3, SHIELD = 4, HEALTHPOTION = 5, MANAPOTION = 6,
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

void increaseStat (Character *character, int stat, int amount);

int calculateStatIncrease (Character *character, int amount);

void levelUp (Character *character);

void setCharacterArmor (Character *character, int newArmor);

int getCharacterArmor (Character *character);

void setCharacterWeaponDamage (Character *character, int newWeaponDamage);

int getCharacterWeaponDamage (Character *character);

void setCharacterMaxHealthPoints (Character *character, int newMaxHealthPoints);

int getCharacterMaxHealthPoints (Character *character);

void setCharacterMaxManaPoints (Character *character, int newMaxManaPoints);

int getCharacterMaxManaPoints (Character *character);

void setCharacterManaPoints (Character *character, int newManaPoints);

int getCharacterManaPoints (Character *character);

void setCharacterName (Character *character, char newName[50]);
#endif