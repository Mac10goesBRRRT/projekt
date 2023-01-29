#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
#include "spell.h"

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

void setCharacterName (Character *character, char *newName) {
    strcpy(character->name,newName);
}

char* getCharacterName (Character *character) {
    return character->name;
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

void setCharacterWeaponClass (Character* character, int weaponClass) {
    character->weaponClass = weaponClass;
}

int getCharacterWeaponClass (Character* character) {
    return character->weaponClass;
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

int calculateDamage (Character *character,Weapon *weapon) {
    switch (character->weaponClass)
    {
        case 1:
            return character->strength*weapon->attack;
        case 2:
            return character->dexterity*weapon->attack;
        case 3:
            return character->intelligence*weapon->attack;
        default:
            return 1;
    }
}

void setCharacterStatPoints (Character* character, int newStatPoints) {
    character->statPoints = newStatPoints;
}

int getCharacterStatPoints (Character* character) {
    return character->statPoints;
}

void initializeCharacter (Character *character,int weaponClass) {
    setCharacterHealthPoints(character,100);
    setCharacterStrength(character,10);
    setCharacterDexterity(character,10);
    setCharacterIntelligence(character,10);
    setCharacterLevel(character,1);
    setCharacterExp(character,0);
    setCharacterMaxExp(character,100);
    setCharacterMaxHealthPoints(character,100);
    setCharacterAttack(character,10);
    setCharacterArmor(character,0);
    setCharacterGold(character,0);
    setCharacterName(character,"Player");
    setCharacterWeaponClass(character,weaponClass);
    setCharacterStatPoints(character,0);
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

void setCharacterStatus (Character *character, int newStatus) {
    character->status = newStatus;
}

int getCharacterStatus (Character *character) {
    return character->status;
}

void setCharacterStatusDuration (Character *character, int newStatusDuration) {
    character->statusDuration = newStatusDuration;
}

int getCharacterStatusDuration (Character *character) {
    return character->statusDuration;
}

void initializeInventory (Character *character) {
    for (int i = 0; i < 10; i++)
    {
        character->inventory[i] = NULL;
    }
}

void putItemInInventory (Character *character, Item *item,int inventorySlot) {
   if(inventorySlot > 9) {
        printf("Inventory slot is out of range (0-9)\n");
   } else if (inventorySlot < 0) {
        printf("Inventory slot is out of range (0-9)\n");
    } else if (character->inventory[inventorySlot] == NULL) {
        printf("Inventory slot is already occupied\n");
    } else {
        character->inventory[inventorySlot] = item;
    }
}
Item * getItemInInventory (Character *character, int inventorySlot) {
    if(inventorySlot > 9) {
        printf("Inventory slot is out of range (0-9)\n");
        return NULL;
    } else if (inventorySlot < 0) {
        printf("Inventory slot is out of range (0-9)\n");
        return NULL;
    } else if (character->inventory[inventorySlot] == NULL) {
        printf("Inventory slot is empty\n");
        return NULL;
    } else {
        return character->inventory[inventorySlot];
    }
}

int checkStatus (Character *character) {
    switch (character->status)
    {
    case SPELL_EFFECT_NONE:
        break;
    case SPELL_EFFECT_BURN:
        setCharacterStatusDuration(character,getCharacterStatusDuration(character)-1);
        if (getCharacterStatusDuration == 0) {
            setCharacterStatus(character,SPELL_EFFECT_NONE);
        }
        return getCharacterStatus(character);
        break;
    case SPELL_EFFECT_FREEZE:
        setCharacterStatusDuration(character,getCharacterStatusDuration(character)-1);
        if (getCharacterStatusDuration == 0) {
            setCharacterStatus(character,SPELL_EFFECT_NONE);
        }
        return getCharacterStatus(character);
        break;
    case SPELL_EFFECT_STUN:
        setCharacterStatusDuration(character,getCharacterStatusDuration(character)-1);
        if (getCharacterStatusDuration == 0) {
            setCharacterStatus(character,SPELL_EFFECT_NONE);
        }
        return getCharacterStatus(character);
        break;
    case SPELL_EFFECT_REGENERATION:
        setCharacterStatusDuration(character,getCharacterStatusDuration(character)-1);
        if (getCharacterStatusDuration == 0) {
            setCharacterStatus(character,SPELL_EFFECT_NONE);
        }
        return getCharacterStatus(character);
        break;
    default:
        return getCharacterStatus(character);
        break;
    }
}