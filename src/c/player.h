#ifndef PLAYER_H
#define PLAYER_H

#include "items.h"

typedef struct
{
    int id;
    int itemCounter;
    Item itemInventory[100];
    int wallet;
} Player;

Player addItemToInventory(Item *availableItem, int itemIndex, Player actualPlayer);
Player removeItemFromInventory(int index, Player actualPlayer);

void showInventory(Player actualPlayer);

#endif