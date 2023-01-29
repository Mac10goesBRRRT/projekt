#ifndef SPELL_H
#define SPELL_H

#include "character.h"

typedef struct {
    int damage, healing, manaCost, effect, effectDuration;
} SpellEffect;

enum {
    SPELL_EFFECT_NONE = 0, SPELL_EFFECT_BURN = 1, SPELL_EFFECT_FREEZE = 2, SPELL_EFFECT_STUN =3 , SPELL_EFFECT_REGENERATION = 4
};


SpellEffect spellFireball(Character *character);
SpellEffect spellHeal(Character *character);

#endif