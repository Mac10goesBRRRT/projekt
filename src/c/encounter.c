#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "character.h"
#include "encounter.h"

#include "playerinput.h"
#include "helper.h"
#include "utils.h"

/*Gegner mit AC, damagedealt = damage-AC, kann nicht kleiner 1 sein
evtl. lair bonus der dem gegner ein wenig mehr/weniger damage erlaubt
gegner erhalten eine zufällige menge Gold, die beim tod an den spieler gegeben werden
humanoide gegner haben heiltränke mit denen sie sich ggf heilen.
heilung erfolgt dann, wenn bestimmte hp (50%) unterschritten wird. wird allerdings gewürfelt,
je niedriger die hp%, desto höher die chance. */

bool playerAlive(Character *character)
{
    if (getCharacterHealthPoints(character) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int playerHeal(Character* character, int amount)
{
    setCharacterHealthPoints(character, getCharacterHealthPoints(character)+ amount);
    if (getCharacterHealthPoints(character) > getCharacterMaxHealthPoints(character))
    {
        setCharacterHealthPoints(character, getCharacterMaxHealthPoints(character));
    }
    return getCharacterHealthPoints(character);
}

int playerDamaged(enemy* enemy, Character* character)
{
    int damagedealt = getEnemyDamage(enemy) - getCharacterArmor(character);
    if (damagedealt < 1)
    {
        damagedealt = 1;
    }
    return getCharacterHealthPoints(character) - damagedealt;
}

void enemyHeal(enemy *enemy, int healAmount)
{
    if (getEnemyHealth(enemy) + healAmount > getEnemyMaxHealth(enemy))
    {
        healAmount = getEnemyMaxHealth(enemy) - getEnemyHealth(enemy);
    }
    setEnemyHealth(enemy, getEnemyHealth(enemy) + healAmount);
}

void enemyDamaged(enemy *enemy,Character* character)
{
    int damagedealt = getCharacterAttack(character) - getEnemyArmor(enemy);
    if (damagedealt < 1)
    {
        damagedealt = 1;
    }
    setEnemyHealth(enemy, getEnemyHealth(enemy) - damagedealt);
}



int switchTurns(int currentTurn)
{
    currentTurn = currentTurn % 2 + 1;
    return currentTurn;
}

int fight(Character *character, enemy* enemy)
{
    int playerH = 0;
    int currentTurn = 2;
    char decision;
    while (playerAlive(character) && getEnemyHealth(enemy) > 0)
    {
        if (currentTurn != 1)
        {
            decision = playerInputChar();
            switch(decision){
                case 'a':
                    enemyDamaged(enemy, character);
                    break;
                case 'h':
                    playerH = playerHeal(character,10);
                    setCharacterHealthPoints(character, playerH);
                    break;
                case 'f':
                    return 2;
            }
            
        }
        else
        {
            if(enemyChoosesHeal(enemy))
            {
                enemyHeal(enemy, 10);
            }
            else
            {
                playerH = playerDamaged(enemy, character);
                setCharacterHealthPoints(character, playerH);
            }
        }
        currentTurn = switchTurns(currentTurn);
    }
    if (playerAlive(character))
    {
        setCharacterExp(character, getCharacterExp(character) + getEnemyExp(enemy));
        setCharacterGold(character, getCharacterGold(character) + getEnemyGold(enemy));
        return 1;
    }
    else
    {
        return 0;
    }
}

int rollInitiative (Character *character) {
    return randomIntRange(1,20) + character->dexterity;
}

bool enemyChoosesHeal(enemy* enemy)
{
    int currentHealth = getEnemyHealth(enemy);
    int maxHealth = getEnemyMaxHealth(enemy);
    int healthd20 = 20 - map(currentHealth, 0, maxHealth, 0, 20);
    int rolld20 = randomIntRange(1, 20);
    if((healthd20 + rolld20) >= 30 && getEnemyHealPotions(enemy) > 0)
    {
        setEnemyHealPotions(enemy, getEnemyHealPotions(enemy) - 1);
        return true;
    }
    else
    {
        return false;
    }
}

// Getter/Setter Funktionen
void setEnemyHealth(enemy* enemy, int newhealth)
{
    enemy->health = newhealth;
}

void setEnemyDamage(enemy* enemy, int newdamage)
{
    enemy->damage = newdamage;
}

void setEnemyArmor(enemy* enemy, int newarmor)
{
    enemy->armor = newarmor;
}

int getEnemyHealth(enemy* enemy)
{
    return enemy->health;
}

int getEnemyArmor(enemy* enemy)
{
    return enemy->armor;
}

int getEnemyDamage(enemy* enemy)
{
    return enemy->damage;
}

int getEnemyMaxHealth(enemy* enemy)
{
    return enemy->maxHealth;
}

int getEnemyHealPotions(enemy* enemy)
{
    return enemy->healPotions;
}

void setEnemyHealPotions(enemy* enemy, int newPotions)
{
    enemy->healPotions = newPotions;
}

int getEnemyExp(enemy* enemy){
    return enemy->exp;
}
void setEnemyExp(enemy* enemy, int newExp){
    enemy->exp = newExp;
}

int getEnemyGold(enemy* enemy){
    return enemy->gold;
}