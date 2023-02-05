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

int getTypeID(Weapon *weapon)
{
    return weapon->typeID;
}

void setTypeID(Weapon *weapon, int typeToSet)
{
    weapon->typeID = typeToSet;
}

int getDamageModifier(Weapon *weapon)
{
    return weapon->damageModifier;
}

void setDamageModifier(Weapon *weapon, int modifierSet)
{
    weapon->damageModifier = modifierSet;
}

int getBaseDamage(Weapon *weapon)
{
    return weapon->baseDamage;
}

void setBaseDamage(Weapon *weapon, int baseDmgSet)
{
    weapon->baseDamage = baseDmgSet;
}

bool getAvailable(Weapon *weapon)
{
    return weapon->canBeUsed;
}

void setAvailable(Weapon *weapon, bool availableSet)
{
    weapon->canBeUsed = availableSet;
}