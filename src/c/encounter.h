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
    int gold;
} enemy; 


bool playerAlive(Character *character);
int playerHeal(Character* character,int amount);
int playerDamaged(enemy* enemy, Character* character);
int rollInitiative (Character *character);
void enemyHeal(enemy *enemy, int healAmount);
void enemyDamaged(enemy* enemy, int damage);
bool enemyChoosesHeal(enemy* enemy);
int switchTurns(int currentTurn);
int fight(Character *character, enemy* enemy);



//Getter/Setter Funktionen
int getEnemyMaxHealth(enemy* enemy);

int getEnemyGold(enemy* enemy);

int getEnemyHealth(enemy* enemy);
void setEnemyHealth(enemy* enemy, int newhealth);

int getEnemyArmor(enemy* enemy);
void setEnemyArmor(enemy* enemy, int newarmor);

int getEnemyDamage(enemy* enemy);
void setEnemyDamage(enemy* enemy, int newdamage);

int getEnemyHealPotions(enemy* enemy);
void setEnemyHealPotions(enemy* enemy, int newPotions);

int getEnemyExp(enemy* enemy);
void setEnemyExp(enemy* enemy, int newExp);

#endif