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


bool playerAlive(Player *player);
int playerHeal(Player* player,int amount);
int playerDamaged(enemy* enemy, Player* player);
int rollInitiative (Player *player);
void enemyHeal(enemy *enemy, int healAmount);
void enemyDamaged(enemy* enemy, Player* player);
bool enemyChoosesHeal(enemy* enemy);
int switchTurns(int currentTurn);
int fight(Player *player, enemy* enemy);
bool dodge (Player *player, enemy* enemy);
void rest(Player *player);



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

int createRandomEnemy(enemy* enemy);

#endif