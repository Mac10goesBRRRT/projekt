#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <stdbool.h>

typedef struct enemy{
    int health;
    int damage;
    int armor;
    int maxHealth;
    int healPotions;
    int exp;
} enemy; 


bool playerAlive(int health);
int playerHeal(int health, int damage, Character* character);
int playerDamaged(int health, int damage, int armor, Character* character);
void enemyHeal(enemy *enemy, int healAmount);
void enemyDamaged(enemy* enemy, int damage);
bool enemyChoosesHeal(enemy* enemy);
int switchTurns(int currentTurn);
int fight(Character *character, enemy* enemy);

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

int getEnemyHealPotions(enemy* enemy);
void setEnemyHealPotions(enemy* enemy, int newPotions);

int getEnemyExp(enemy* enemy);
void setEnemyExp(enemy* enemy, int newExp);

#endif