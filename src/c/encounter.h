#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <stdbool.h>

typedef struct enemy{
    int health;
    int damage;
    int armor;
    int maxHealth;
} enemy; 


bool playerAlive(int health);
int playerHealth(int health, int damage, int armor);
void enemyDamaged(enemy* enemy, int damage);
int switchTurns(int currentTurn);
int fight(int playerH, int playerDamage, int playerArmor, int playerAttack, enemy* enemy);



int randomIntRange(int min, int max);
//Getter/Setter Funktionen

//setEnemyHealth(&enemy, health);
void setEnemyHealth(enemy* enemy, int newhealth);

//setEnemyDamage(&enemy.damage, damage);
void setEnemyDamage(enemy* enemy, int newdamage);
//setEnemyArmor(&enemy.armor, armor);
void setEnemyArmor(enemy* enemy, int newarmor);
//Function to get the value of Data in a struct, needs a pointer to the struct
int getEnemyMaxHealth(enemy* enemy);
int getEnemyHealth(enemy* enemy);
int getEnemyArmor(enemy* enemy);
int getEnemyDamage(enemy* enemy);

#endif