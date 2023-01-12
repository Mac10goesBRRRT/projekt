#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <stdbool.h>

typedef struct {
    int health;
} enemy; 

//setEnemyHealth(&enemy.health, health);
void *setEnemyHealth(int *num, int health);
int getEnemyHealth(enemy enemy);
bool playerAlive(int health);
int playerHealth(int health, int damage);

#endif