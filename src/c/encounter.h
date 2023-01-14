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
int playerHealth(int health, int damage, int armor);
int enemyDamaged(enemy enemy, int damage);
int switchTurns(int currentTurn);
int fight(int playerH, int playerDamage, int playerArmor, int playerAttack, enemy enemy);


//Getter/Setter Funktionen

//setEnemyHealth(&enemy.health, health);
void *setEnemyHealth(int *num, int health);

//setEnemyDamage(&enemy.damage, damage);
void *setEnemyDamage(int *num, int damage);
//setEnemyArmor(&enemy.armor, armor);
void *setEnemyArmor(int *num, int damage);
//Function to get the value of Data in a struct, needs a pointer to the struct
int getEnemyInt(int *structParam);

#endif