#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "character.h"
#include "encounter.h"
#include "spell.h"

#include "playerinput.h"
#include "helper.h"
#include "utils.h"

/*Gegner mit AC, damagedealt = damage-AC, kann nicht kleiner 1 sein
evtl. lair bonus der dem gegner ein wenig mehr/weniger damage erlaubt
gegner erhalten eine zufällige menge Gold, die beim tod an den spieler gegeben werden
humanoide gegner haben heiltränke mit denen sie sich ggf heilen.
heilung erfolgt dann, wenn bestimmte hp (50%) unterschritten wird. wird allerdings gewürfelt,
je niedriger die hp%, desto höher die chance. */

bool playerAlive(Player *player)
{
    if (getPlayerHealthPoints(player) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int playerHeal(Player* player, int amount)
{
    setPlayerHealthPoints(player, getPlayerHealthPoints(player)+ amount);
    if (getPlayerHealthPoints(player) > getPlayerMaxHealthPoints(player))
    {
        setPlayerHealthPoints(player, getPlayerMaxHealthPoints(player));
    }
    return getPlayerHealthPoints(player);
}

int playerDamaged(enemy* enemy, Player* player)
{
    int damagedealt = getEnemyDamage(enemy) - getPlayerArmor(player);
    if (damagedealt < 1)
    {
        damagedealt = 1;
    }
    return getPlayerHealthPoints(player) - damagedealt;
}

void enemyHeal(enemy *enemy, int healAmount)
{
    if (getEnemyHealth(enemy) + healAmount > getEnemyMaxHealth(enemy))
    {
        healAmount = getEnemyMaxHealth(enemy) - getEnemyHealth(enemy);
    }
    setEnemyHealth(enemy, getEnemyHealth(enemy) + healAmount);
}

void enemyDamaged(enemy *enemy,Player* player)
{
    int damagedealt = getPlayerAttack(player) - getEnemyArmor(enemy);
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

int fight(Player *player, enemy* enemy)
{
    int playerH = 0;
    int currentTurn = 2;
    char decision;
    while (playerAlive(player) && getEnemyHealth(enemy) > 0)
    {
        if (currentTurn != 1)
        {
            decision = playerInputChar();
            switch(decision){
                case 'a':
                    enemyDamaged(enemy, player);
                    break;
                case 'h':
                    playerH = playerHeal(player,10);
                    setPlayerHealthPoints(player, playerH);
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
                playerH = playerDamaged(enemy, player);
                setPlayerHealthPoints(player, playerH);
            }
        }
        currentTurn = switchTurns(currentTurn);
    }
    if (playerAlive(player))
    {
        setPlayerExp(player, getPlayerExp(player) + getEnemyExp(enemy));
        setPlayerGold(player, getPlayerGold(player) + getEnemyGold(enemy));
        return 1;
    }
    else
    {
        return 0;
    }
}

int rollInitiative (Player *player) {
    return randomIntRange(1,20) + player->dexterity;
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
int setEnemyGold(enemy* enemy, int newGold){
    enemy->gold = newGold;
}

int createRandomEnemy(enemy* enemy)
{
    int enemyType = randomIntRange(1, 3);
    switch(enemyType)
    {
        case 1:
            setEnemyHealth(enemy, 20);
            setEnemyDamage(enemy, 5);
            setEnemyArmor(enemy, 2);
            setEnemyHealPotions(enemy, 1);
            setEnemyExp(enemy, 10);
            setEnemyGold(enemy, 10);
            break;
        case 2:
            setEnemyHealth(enemy, 30);
            setEnemyDamage(enemy, 10);
            setEnemyArmor(enemy, 5);
            setEnemyHealPotions(enemy, 2);
            setEnemyExp(enemy, 20);
            setEnemyGold(enemy, 20);
            break;
        case 3:
            setEnemyHealth(enemy, 40);
            setEnemyDamage(enemy, 15);
            setEnemyArmor(enemy, 10);
            setEnemyHealPotions(enemy, 3);
            setEnemyExp(enemy, 30);
            setEnemyGold(enemy, 30);
            break;
    }
    return enemyType;
}

bool dodge (Player *player, enemy* enemy) {
    if (randomIntRange(1,20) + player->dexterity > 15)
    {
        return true;
    }
    return false;
}

void rest(Player *player) {
    setPlayerHealthPoints(player, getPlayerMaxHealthPoints(player));
    setPlayerManaPoints(player, 10);
    setPlayerStatus(player, SPELL_EFFECT_NONE);
    setPlayerStatusDuration(player, 0);
}