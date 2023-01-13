#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <encounter.h>
/*Gegner mit AC, damagedealt = damage-AC, kann nicht kleiner 1 sein
evtl. lair bonus der dem gegner ein wenig mehr/weniger damage erlaubt
gegner erhalten eine zufällige menge Gold, die beim tod an den spieler gegeben werden
humanoide gegner haben heiltränke mit denen sie sich ggf heilen. 
heilung erfolgt dann, wenn bestimmte hp (50%) unterschritten wird. wird allerdings gewürfelt, 
je niedriger die hp%, desto höher die chance. */

bool playerAlive(int health){
    if(health > 0){
        return true;
    }
    else{
        return false;
    }
}

int playerHealth(int health, int damage){
    const int maxhealth = 100;
    health = health - damage;
    if(health > maxhealth){
        health = maxhealth;
    }
    return health;
}

/* enemy createEnemy(int health)
{
    enemy test;
    test.health = health;
    return test;
} */

void *setEnemyHealth(int *num, int health){
    *num = health;
    //return health;
}

int getEnemyHealth(enemy enemy){
    //gibt health zurück, benötigt keine adress pointer
    return enemy.health;
}

void *setEnemyDamage(int *num, int damage){
    *num = damage;
}

int getEnemyDamage(enemy enemy){
    return enemy.damage;
}

void *setEnemyArmor(int *num, int armor){
    *num = armor;
}

int getEnemyArmor(enemy enemy){
    return enemy.armor;
}

