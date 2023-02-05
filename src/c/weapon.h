#ifndef WEAPON_H
#define WEAPON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int id;
    char *fullName;
    char *name;
    int typeID;
    char *typeName;
    int damageModifier;
    int baseDamage;
    bool canBeUsed;
} Weapon;

char *getName(Weapon *weapon);
void setName(Weapon *weapon, char *nameToSet);

char *getFullName(Weapon *weapon);
void setFullName(Weapon *weapon, char *fullNameToSet);

int getTypeID(Weapon *weapon);
void setTypeID(Weapon *weapon, int typeToSet);

// typeName placeholder

int getDamageModifier(Weapon *weapon);
void setDamageModifier(Weapon *weapon, int modifierSet);

int getBaseDamage(Weapon *weapon);
void setBaseDamage(Weapon *weapon, int baseDmgSet);

bool getAvailable(Weapon *weapon);
void setAvailable(Weapon *weapon, bool availableSet);

#endif