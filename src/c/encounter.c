#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "encounter.h"

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

int enemyDamaged(enemy enemy, int damage)
{
    int armor = getEnemyArmor(&enemy);
    int damagedealt = damage - armor;
    if (damagedealt < 1)
    {
        damagedealt = 1;
    }
    enemy.health = enemy.health - damagedealt;
    return enemy.health;
}



int switchTurns(int currentTurn)
{
    currentTurn = currentTurn % 2 + 1;
    return currentTurn;
}

int fight(int playerH, int playerDamage, int playerArmor, int playerAttack, enemy enemy)
{
    int currentTurn = 0;
    while (playerAlive(playerH) && getEnemyHealth(&enemy) > 0)
    {
        if (currentTurn == 0)
        {
            setEnemyHealth(&enemy.health, enemyDamaged(enemy, playerDamage));
        }
        else
        {
            playerH = playerHealth(playerH, getEnemyDamage(&enemy), playerArmor);
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
void *setEnemyHealth(int *num, int health)
{
    *num = health;
    // return health;
}

void *setEnemyDamage(int *num, int damage)
{
    *num = damage;
}

void *setEnemyArmor(int *num, int armor)
{
    *num = armor;
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