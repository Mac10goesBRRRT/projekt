#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int strength,dexterity,intelligence,healthPoints,manaPoints,level,exp,maxExp;
    int attack,armor,maxHealthPoints,gold,*items[10],weaponClass,statPoints;
    char name [50];
} Character;
typedef struct {
    int attack,durability;
    char name [50];
} Weapon;
typedef struct {
    int id,amount,damage,healing,mana;
    char name [50];
 } Item;


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

void setCharacterWeaponClass (Character *character, int newWeaponClass);

int getCharacterWeaponClass (Character *character);

int getWeaponAttack (Weapon *weapon);

void setWeaponAttack (Weapon *weapon, int newAttack);

int getWeaponDurability (Weapon *weapon);

int setWeaponDurability (Weapon *weapon, int newDurability);

int calculateDamage (Character *character,Weapon *weapon);

void setCharacterStatPoints (Character *character, int newStatPoints);

int getCharacterStatPoints (Character *character);

void initializeCharacter (Character *character,int weaponClass);

void setItemID (Item *item, int newID);

int getItemID (Item *item);

void setItemAmount (Item *item, int newAmount);

int getItemAmount (Item *item);

void setItemDamage (Item *item, int newDamage);

int getItemDamage (Item *item);

void setItemHealing (Item *item, int newHealing);

int getItemHealing (Item *item);

void setItemMana (Item *item, int newMana);

int getItemMana (Item *item);

void setItemName (Item *item, char newName[]);

char* getItemName (Item *item);


#endif