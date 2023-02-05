#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "player.h"


// PLAYER INVENTORY
Player addItemToInventory(Item *availableItems, int itemIndex, Player actualPlayer)
{
    int counter = actualPlayer.itemCounter;
    actualPlayer.itemInventory[counter] = availableItems[itemIndex - 1]; // -1 to get right index (items begin - 1,2,3,4...)
    actualPlayer.itemCounter += 1;

    return actualPlayer;
}