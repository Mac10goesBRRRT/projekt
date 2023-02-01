#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int id,amount,damage,healing,mana;
    char name [50];
 } Item;
typedef struct {
    int strength,dexterity,intelligence,healthPoints,manaPoints,level,exp,maxExp;
    int attack,armor,maxHealthPoints,gold,weaponClass,statPoints,status,statusDuration;
    char name [50];
    Item *inventory[10];
} Player;
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

void setPlayerHealthPoints (Player *player, int newHealthPoints);

int getPlayerHealthPoints (Player *player);

void setPlayerStrength (Player *player, int newStrength);

int getPlayerStrength (Player *player);

void setPlayerDexterity (Player *player, int newDexterity);

int getPlayerDexterity (Player *player);

void setPlayerIntelligence (Player *player, int newIntelligence);

int getPlayerIntelligence (Player *player);

void setPlayerLevel (Player *player, int newLevel);

int getPlayerLevel (Player *player);

void setPlayerExp (Player *player, int newExp);

int getPlayerExp (Player *player);

void setPlayerMaxExp (Player *player, int newMaxExp);

int getPlayerMaxExp (Player *player);

void increaseStat (Player *player, int stat, int amount);

int calculateStatIncrease (Player *player, int amount);

void setPlayerMaxHealthPoints (Player *player, int newMaxHealthPoints);

int getPlayerMaxHealthPoints (Player *player);

void setPlayerAttack (Player *player, int newAttack);

int getPlayerAttack (Player *player);

void setPlayerArmor (Player *player, int newArmor);

int getPlayerArmor (Player *player);

void setPlayerGold (Player *player, int newGold);

int getPlayerGold (Player *player);

void levelUp (Player *player);

void setPlayerName (Player *player, char newName[]);

char* getPlayerName (Player *player);

void setPlayerWeaponClass (Player *player, int newWeaponClass);

int getPlayerWeaponClass (Player *player);

int getWeaponAttack (Weapon *weapon);

void setWeaponAttack (Weapon *weapon, int newAttack);

int getWeaponDurability (Weapon *weapon);

int setWeaponDurability (Weapon *weapon, int newDurability);

int calculateDamage (Player *player,Weapon *weapon);

void setPlayerStatPoints (Player *player, int newStatPoints);

int getPlayerStatPoints (Player *player);

void initializePlayer (Player *player,int weaponClass);

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

void putItemInInventory (Player *player, Item *item, int inventorySlot);

void initializeInventory (Player *player);

Item * getItemInInventory (Player *player, int inventorySlot);

void setPlayerStatus (Player *player, int newStatus);

int getPlayerStatus (Player *player);

void setPlayerStatusDuration (Player *player, int newStatusDuration);

int getPlayerStatusDuration (Player *player);

int checkStatus (Player *player);

void setPlayerManaPoints (Player *player, int newManaPoints);

int getPlayerManaPoints (Player *player);
#endif