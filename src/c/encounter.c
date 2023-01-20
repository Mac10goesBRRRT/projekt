#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "encounter.h"
#include "playerinput.h"

/*Gegner mit AC, damagedealt = damage-AC, kann nicht kleiner 1 sein
evtl. lair bonus der dem gegner ein wenig mehr/weniger damage erlaubt
gegner erhalten eine zufällige menge Gold, die beim tod an den spieler gegeben werden
humanoide gegner haben heiltränke mit denen sie sich ggf heilen.
heilung erfolgt dann, wenn bestimmte hp (50%) unterschritten wird. wird allerdings gewürfelt,
je niedriger die hp%, desto höher die chance. */

bool playerAlive(int health)
{
    if (health > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int playerHealth(int health, int damage, int armor)
{
    const int maxhealth = 100;
    health = health - damage;
    if (health > maxhealth)
    {
        health = maxhealth;
    }
    return health;
}

void enemyDamaged(enemy *enemy, int damage)
{
    int armor = getEnemyArmor(enemy);
    int currentHealth = getEnemyHealth(enemy);
    int damagedealt = damage - armor;
    if (damagedealt < 1)
    {
        damagedealt = 1;
    }
    setEnemyHealth(enemy, currentHealth - damagedealt);
}



int switchTurns(int currentTurn)
{
    currentTurn = currentTurn % 2 + 1;
    return currentTurn;
}

int fight(int playerH, int playerDamage, int playerArmor, int playerAttack, enemy* enemy)
{
    int currentTurn = 0;
    char decision;
    while (playerAlive(playerH) && getEnemyHealth(enemy) > 0)
    {
        if (currentTurn != 1)
        {
            decision = playerInput();
            switch(decision){
                case 'a':
                    enemyDamaged(enemy, playerDamage);
                    break;
                case 'h':
                    playerH = playerHealth(playerH, -10, playerArmor);
                    break;
                case 'f':
                    return 2;
            }
            
        }
        else
        {
            playerH = playerHealth(playerH, getEnemyDamage(enemy), playerArmor);
        }
        currentTurn = switchTurns(currentTurn);
    }
    if (playerAlive(playerH))
    {
        return 1;
    }
    else
    {
        return 0;
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

int getEnemyAttack(enemy* enemy)
{
    return enemy->attack;
}