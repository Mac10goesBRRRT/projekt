#include "weapon.h"

char *getName(Weapon *weapon){
    return weapon->name;
}

void setName(Weapon *weapon, char *nameToSet){
    weapon->name = nameToSet;
}