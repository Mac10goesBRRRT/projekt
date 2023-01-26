#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int strength,dexterity,intelligence,healthPoints,manaPoints,level,exp,maxExp;
    int attack,armor,maxHealthPoints,gold,items[10],weapon;
    char name [50];
} Character;
typedef struct {
    int attack,durability;
    char name [50];
} Weapon;

enum {
    SWORD = 1, BOW = 2, STAFF = 3
};
enum {
    STRENGTH = 1, DEXTERITY = 2, INTELLIGENCE = 3, HEALTHPOINTS = 4, MANAPOINTS = 5, LEVEL = 6, EXP = 7, MAXEXP = 8
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

void setCharacterMaxHealthPoints (Character *character, int newMaxHealthPoints);

int getCharacterMaxHealthPoints (Character *character);

void setCharacterAttack (Character *character, int newAttack);

int getCharacterAttack (Character *character);

void setCharacterArmor (Character *character, int newArmor);

int getCharacterArmor (Character *character);

void setCharacterGold (Character *character, int newGold);

int getCharacterGold (Character *character);

void levelUp (Character *character);

void setCharacterName (Character *character, char newName[]);

char* getCharacterName (Character *character);

int getWeaponAttack (Weapon *weapon);

void setWeaponAttack (Weapon *weapon, int newAttack);

int getWeaponDurability (Weapon *weapon);

int setWeaponDurability (Weapon *weapon, int newDurability);

#endif