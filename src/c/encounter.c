#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "character.h"
#include "encounter.h"

#include "playerinput.h"
#include "helper.h"

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

int playerHealth(int health, int damage, int armor, Character* character)
{
    int maxhealth = getCharacterMaxHealthPoints(character);
    health = health - damage;
    if (health > maxhealth)
    {
        health = maxhealth;
    }
    return health;
}

void enemyHeal(enemy *enemy, int healAmount)
{
    int currentHealth = getEnemyHealth(enemy);
    int maxHealth = getEnemyMaxHealth(enemy);
    if (currentHealth + healAmount > maxHealth)
    {
        healAmount = maxHealth - currentHealth;
    }
    setEnemyHealth(enemy, currentHealth + healAmount);
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

int fight(Character *character, enemy* enemy)
{
    int playerH = 0;
    int currentTurn = 2;
    char decision;
    while (playerAlive(getCharacterHealthPoints(character)) && getEnemyHealth(enemy) > 0)
    {
        if (currentTurn != 1)
        {
            decision = playerInputChar();
            switch(decision){
                case 'a':
                    enemyDamaged(enemy, getCharacterAttack(character));
                    break;
                case 'h':
                    playerH = playerHealth(getCharacterHealthPoints(character), -10, getCharacterArmor(character), character);
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
                playerH = playerHealth(getCharacterHealthPoints(character), getEnemyDamage(enemy), getCharacterArmor(character), character);
                setCharacterHealthPoints(character, playerH);
            }
        }
        currentTurn = switchTurns(currentTurn);
    }
    if (playerAlive(getCharacterHealthPoints(character)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int randomIntRange(int min, int max)
{
    int value = randomInt();
    return (value % (max - min + 1)) + min;
}


int map(int x, int in_min, int in_max, int out_min, int out_max)
{
    //vgl Arduino map() https://www.arduino.cc/reference/en/language/functions/math/map/
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

bool enemyChoosesHeal(enemy* enemy)
{
    int currentHealth = getEnemyHealth(enemy);
    int maxHealth = getEnemyMaxHealth(enemy);
    int healthd20 = 20 - map(currentHealth, 0, maxHealth, 0, 20);
    int rolld20 = randomIntRange(1, 20);
    return (healthd20 + rolld20) >= 30;
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