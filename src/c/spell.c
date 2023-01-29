#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
#include "spell.h"

SpellEffect spellFireball(Character *character) {
    SpellEffect fireball;
    fireball.damage = 10 + (getCharacterIntelligence(character) / 2);
    fireball.healing = 0;
    fireball.manaCost = 10;
    fireball.effect = SPELL_EFFECT_NONE;
    fireball.effectDuration = 0;
    return fireball;
}

SpellEffect spellHeal(Character *character) {
    SpellEffect heal;
    heal.damage = 0;
    heal.healing = 10 + (getCharacterIntelligence(character) / 3);
    heal.manaCost = 10;
    heal.effect = SPELL_EFFECT_NONE;
    heal.effectDuration = 0;
    return heal;
}

SpellEffect spellLightning(Character *character) {
    SpellEffect lightning;
    lightning.damage = 10 + (getCharacterIntelligence(character) / 2);
    lightning.healing = 0;
    lightning.manaCost = 10;
    lightning.effect = SPELL_EFFECT_STUN;
    lightning.effectDuration = 1;
    return lightning;
}

SpellEffect spellRegeneration (Character *character) {
    SpellEffect regeneration;
    regeneration.damage = 0;
    regeneration.healing = 5 + (getCharacterIntelligence(character) / 4);
    regeneration.manaCost = 10;
    regeneration.effect = SPELL_EFFECT_REGENERATION;
    regeneration.effectDuration = 2;
    return regeneration;
}