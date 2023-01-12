#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <encounter.h>

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

enemy createEnemy(int health)
{
    enemy test;
    test.health = health;
    return test;
}

void *setEnemyHealth(int *num, int health){
    *num = health;
    //return health;
}

int getEnemyHealth(enemy enemy){
    //gibt health zurück, benötigt keine adress pointer
    return enemy.health;
}
