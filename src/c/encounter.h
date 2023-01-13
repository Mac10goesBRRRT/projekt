#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <stdbool.h>

typedef struct {
    int health;
    int damage;
    int armor;
    int attack;
} enemy; 


bool playerAlive(int health);
int playerHealth(int health, int damage);
int enemyDamaged(enemy enemy, int damage);



//Getter/Setter Funktionen

//setEnemyHealth(&enemy.health, health);
void *setEnemyHealth(int *num, int health);
int getEnemyHealth(enemy enemy);
//setEnemyDamage(&enemy.damage, damage);
void *setEnemyDamage(int *num, int damage);
int getEnemyDamage(enemy enemy);
//setEnemyArmor(&enemy.armor, armor);
void *setEnemyArmor(int *num, int damage);
int getEnemyArmor(enemy enemy);
//Function to get the value of Data in a struct, needs a pointer to the struct
int getEnemyInt(int *structParam);

#endif