#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <stdbool.h>

typedef struct {
    int health;
    int damage;
} enemy; 


bool playerAlive(int health);
int playerHealth(int health, int damage);

//setEnemyHealth(&enemy.health, health);
void *setEnemyHealth(int *num, int health);
int getEnemyHealth(enemy enemy);
//setEnemyDamage(&enemy.damage, damage);
void *setEnemyDamage(int *num, int damage);
int getEnemyDamage(enemy enemy);

#endif