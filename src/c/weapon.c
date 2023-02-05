#include "weapon.h"

char *getName(Weapon *weapon)
{
    return weapon->name;
}

void setName(Weapon *weapon, char *nameToSet)
{
    weapon->name = nameToSet;
}

char *getFullName(Weapon *weapon)
{
    return weapon->fullName;
}

void setFullName(Weapon *weapon, char *fullNameToSet)
{
    weapon->fullName = fullNameToSet;
}