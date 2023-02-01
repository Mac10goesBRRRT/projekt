#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
#include "spell.h"

Player player;

void setPlayerHealthPoints (Player *player, int newHealthPoints){
    player->healthPoints = newHealthPoints;
}

int getPlayerHealthPoints (Player *player) {
    return player->healthPoints;
}

void setPlayerStrength (Player *player, int newStrength) {
   player->strength = newStrength;
}

int getPlayerStrength (Player *player) {
    return player->strength;
}

void setPlayerDexterity (Player *player, int newDexterity) {
    player->dexterity = newDexterity;
}

int getPlayerDexterity (Player *player) {
    return player->dexterity;
}

void setPlayerIntelligence (Player *player, int newIntelligence) {
    player->intelligence = newIntelligence;
}

int getPlayerIntelligence (Player *player) {
    return player->intelligence;
}

void setPlayerLevel (Player *player, int newLevel) {
    player->level = newLevel;
}

int getPlayerLevel (Player *player) {
    return player->level;
}

void setPlayerExp (Player *player, int newExp) {
    player->exp = newExp;
}

int getPlayerExp (Player *player) {
    return player->exp;
}

void setPlayerMaxExp (Player *player, int newMaxExp) {
    player->maxExp = newMaxExp;
}

int getPlayerMaxExp (Player *player) {
    return player->maxExp;
}

int calculateStatIncrease (Player *player, int amount) {
    return player->level*amount;
}

void setPlayerMaxHealthPoints (Player *player, int newMaxHealthPoints){
    player->maxHealthPoints = newMaxHealthPoints;
}

int getPlayerMaxHealthPoints (Player *player){
    return player->maxHealthPoints;
}

void setPlayerAttack (Player *player, int newAttack){
    player->attack = newAttack;
}

int getPlayerAttack (Player *player){
    return player->attack;
}

void setPlayerArmor (Player *player, int newArmor){
    player->armor = newArmor;
}

int getPlayerArmor (Player *player){
    return player->armor;
}

void setPlayerGold (Player *player, int newGold){
    player->gold = newGold;
}

int getPlayerGold (Player *player){
    return player->gold;
}

void setPlayerName (Player *player, char *newName) {
    strcpy(player->name,newName);
}

char* getPlayerName (Player *player) {
    return player->name;
}

int getWeaponAttack (Weapon *weapon) {
    return weapon->attack;
}

void setWeaponAttack (Weapon *weapon, int newAttack) {
    weapon->attack = newAttack;
}

int getWeaponDurability (Weapon *weapon) {
    return weapon->durability;
}

int setWeaponDurability (Weapon *weapon, int newDurability) {
    weapon->durability = newDurability;
}

void setPlayerWeaponClass (Player* player, int weaponClass) {
    player->weaponClass = weaponClass;
}

int getPlayerWeaponClass (Player* player) {
    return player->weaponClass;
}

void increaseStat (Player *player, int stat, int amount) {
    switch (stat)
    {
    case 1:        
        player->strength += amount;break;
    case 2:
        player->dexterity += amount;break;
    case 3:
        player->intelligence += amount;break;
    case 4:
        player->healthPoints += amount;break;
    case 5:
        player->manaPoints += amount;break;
    case 6:
        player->level += amount;break;
    case 7:
        player->exp += amount;break;
    case 8:
        player->maxExp += amount;break;
    default:
        break;
    }
}
void levelUp (Player *player) {
   if (getPlayerExp(player) > getPlayerMaxExp(player)) {
        increaseStat(player,LEVEL,1);
        setPlayerExp(player,getPlayerExp(player)-getPlayerMaxExp(player));
   }
}

int calculateDamage (Player *player,Weapon *weapon) {
    switch (player->weaponClass)
    {
        case 1:
            return player->strength*weapon->attack;
        case 2:
            return player->dexterity*weapon->attack;
        case 3:
            return player->intelligence*weapon->attack;
        default:
            return 1;
    }
}

void setPlayerStatPoints (Player* player, int newStatPoints) {
    player->statPoints = newStatPoints;
}

int getPlayerStatPoints (Player* player) {
    return player->statPoints;
}

void initializePlayer (Player *player,int weaponClass) {
    setPlayerHealthPoints(player,100);
    setPlayerStrength(player,10);
    setPlayerDexterity(player,10);
    setPlayerIntelligence(player,10);
    setPlayerLevel(player,1);
    setPlayerExp(player,0);
    setPlayerMaxExp(player,100);
    setPlayerMaxHealthPoints(player,100);
    setPlayerAttack(player,10);
    setPlayerArmor(player,0);
    setPlayerGold(player,0);
    setPlayerName(player,"Player");
    setPlayerWeaponClass(player,weaponClass);
    setPlayerStatPoints(player,0);
}

void setItemID (Item *item, int newID) {
    item->id = newID;
}

int getItemID (Item *item) {
    return item->id;
}

void setItemAmount (Item *item, int newAmount) {
    item->amount = newAmount;
}

int getItemAmount (Item *item) {
    return item->amount;
}

void setItemDamage (Item *item, int newDamage) {
    item->damage = newDamage;
}

int getItemDamage (Item *item) {
    return item->damage;
}

void setItemHealing (Item *item, int newHealing) {
    item->healing = newHealing;
}

int getItemHealing (Item *item) {
    return item->healing;
}

void setItemMana (Item *item, int newMana) {
    item->mana = newMana;
}

int getItemMana (Item *item) {
    return item->mana;
}

void setItemName (Item *item, char newName[]) {
    strcpy(item->name,newName);
}

char* getItemName (Item *item) {
    return item->name;
}

void setPlayerStatus (Player *player, int newStatus) {
    player->status = newStatus;
}

int getPlayerStatus (Player *player) {
    return player->status;
}

void setPlayerStatusDuration (Player *player, int newStatusDuration) {
    player->statusDuration = newStatusDuration;
}

int getPlayerStatusDuration (Player *player) {
    return player->statusDuration;
}

void initializeInventory (Player *player) {
    for (int i = 0; i < 10; i++)
    {
        player->inventory[i] = NULL;
    }
}

void putItemInInventory (Player *player, Item *item,int inventorySlot) {
   if(inventorySlot > 9) {
        printf("Inventory slot is out of range (0-9)\n");
   } else if (inventorySlot < 0) {
        printf("Inventory slot is out of range (0-9)\n");
    } else if (player->inventory[inventorySlot] == NULL) {
        printf("Inventory slot is already occupied\n");
    } else {
        player->inventory[inventorySlot] = item;
    }
}
Item * getItemInInventory (Player *player, int inventorySlot) {
    if(inventorySlot > 9) {
        printf("Inventory slot is out of range (0-9)\n");
        return NULL;
    } else if (inventorySlot < 0) {
        printf("Inventory slot is out of range (0-9)\n");
        return NULL;
    } else if (player->inventory[inventorySlot] == NULL) {
        printf("Inventory slot is empty\n");
        return NULL;
    } else {
        return player->inventory[inventorySlot];
    }
}

int checkStatus (Player *player) {
    switch (player->status)
    {
    case SPELL_EFFECT_NONE:
        break;
    case SPELL_EFFECT_BURN:
        setPlayerStatusDuration(player,getPlayerStatusDuration(player)-1);
        if (getPlayerStatusDuration == 0) {
            setPlayerStatus(player,SPELL_EFFECT_NONE);
        }
        return getPlayerStatus(player);
        break;
    case SPELL_EFFECT_FREEZE:
        setPlayerStatusDuration(player,getPlayerStatusDuration(player)-1);
        if (getPlayerStatusDuration == 0) {
            setPlayerStatus(player,SPELL_EFFECT_NONE);
        }
        return getPlayerStatus(player);
        break;
    case SPELL_EFFECT_STUN:
        setPlayerStatusDuration(player,getPlayerStatusDuration(player)-1);
        if (getPlayerStatusDuration == 0) {
            setPlayerStatus(player,SPELL_EFFECT_NONE);
        }
        return getPlayerStatus(player);
        break;
    case SPELL_EFFECT_REGENERATION:
        setPlayerStatusDuration(player,getPlayerStatusDuration(player)-1);
        if (getPlayerStatusDuration == 0) {
            setPlayerStatus(player,SPELL_EFFECT_NONE);
        }
        return getPlayerStatus(player);
        break;
    default:
        return getPlayerStatus(player);
        break;
    }
}
void setPlayerManaPoints (Player *player, int newManaPoints) {
    player->manaPoints = newManaPoints;
}

int getPlayerManaPoints (Player *player) {
    return player->manaPoints;
}