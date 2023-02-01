#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
#include "spell.h"

SpellEffect spellFireball(Player *player) {
    SpellEffect fireball;
    fireball.id = 0;
    fireball.damage = 10 + (getPlayerIntelligence(player) / 2);
    fireball.healing = 0;
    fireball.manaCost = 10;
    fireball.effect = SPELL_EFFECT_NONE;
    fireball.effectDuration = 0;
    return fireball;
}

SpellEffect spellHeal(Player *player) {
    SpellEffect heal;
    heal.id = 1;
    heal.damage = 0;
    heal.healing = 10 + (getPlayerIntelligence(player) / 3);
    heal.manaCost = 10;
    heal.effect = SPELL_EFFECT_NONE;
    heal.effectDuration = 0;
    return heal;
}

SpellEffect spellLightning(Player *player) {
    SpellEffect lightning;
    lightning.id = 2;
    lightning.damage = 10 + (getPlayerIntelligence(player) / 2);
    lightning.healing = 0;
    lightning.manaCost = 10;
    lightning.effect = SPELL_EFFECT_STUN;
    lightning.effectDuration = 1;
    return lightning;
}

SpellEffect spellRegeneration (Player *player) {
    SpellEffect regeneration;
    regeneration.id = 3;
    regeneration.damage = 0;
    regeneration.healing = 5 + (getPlayerIntelligence(player) / 4);
    regeneration.manaCost = 10;
    regeneration.effect = SPELL_EFFECT_REGENERATION;
    regeneration.effectDuration = 2;
    return regeneration;
}

SpellEffect spellFreeze(Player *player) {
    SpellEffect freeze;
    freeze.id = 4;
    freeze.damage = 0;
    freeze.healing = 0;
    freeze.manaCost = 10;
    freeze.effect = SPELL_EFFECT_FREEZE;
    freeze.effectDuration = 2;
    return freeze;
}