#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"

int spellFireball(Character *character) {
    int damage = 10 + (getCharacterIntelligence(character) / 2);
    return damage;
}