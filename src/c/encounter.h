#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <stdbool.h>
#include "character.h"

typedef struct enemy{
    int health;
    int damage;
    int armor;
    int maxHealth;
} enemy; 


bool playerAlive(Character* character);
int playerHealth(int health, int damage, int armor);
void enemyHeal(enemy *enemy, int healAmount);
void enemyDamaged(enemy* enemy, int damage);
bool enemyChoosesHeal(enemy* enemy);
int rollInitiative (Character *character);
int switchTurns(int currentTurn);
int fight(Character* character, enemy* enemy);

//Funktionen die Mathematische Berechnungen durchführen
int map(int x, int in_min, int in_max, int out_min, int out_max);
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