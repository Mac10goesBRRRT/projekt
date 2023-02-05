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

#endif