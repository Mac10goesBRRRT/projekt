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

//add and remove items
Player addItemToInventory(Item *availableItem, int itemIndex, Player actualPlayer);
Player removeItemFromInventory(int index, Player actualPlayer);

//currency
Player setTotal(Player actualPlayer, int value);
Player addMoneyToPlayer(Player actualPlayer, int money);
Player removeMoneyFromPlayer(Player actualPlayer, int money);

//add and remove items with currency
Player buyItem(Item *availableItems, int itemIndex, Player actualPlayer);

//show
void showInventory(Player actualPlayer);

#endif