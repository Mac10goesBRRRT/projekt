#ifndef SPELL_H
#define SPELL_H


typedef struct {
    int id,damage, healing, manaCost, effect, effectDuration;
} SpellEffect;

enum {
    SPELL_EFFECT_NONE = 0, SPELL_EFFECT_BURN = 1, SPELL_EFFECT_FREEZE = 2, SPELL_EFFECT_STUN =3 , SPELL_EFFECT_REGENERATION = 4
};


SpellEffect spellFireball(Player *player);
SpellEffect spellHeal(Player *player);
SpellEffect spellLightning(Player *player);
SpellEffect spellRegeneration (Player *player);
SpellEffect spellFreeze(Player *player);


#endif