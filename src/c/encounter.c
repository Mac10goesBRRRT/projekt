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
