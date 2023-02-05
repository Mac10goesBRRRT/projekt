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

void showInventory(Player actualPlayer)
{
    int inventoryItemCounter = actualPlayer.itemCounter;

    if (inventoryItemCounter == 0)
    {
        printf("*** Inventory is empty *** \n\n");
    }
    else
    {
        printf("*** Inventory *** \n\n");

        for (int i = 0; i < actualPlayer.itemCounter; i++)
        {
            // printf("%d: %d - %s\n", i, inventory[i].id, inventory[i].itemName);
            printf("> %s - %d\n", actualPlayer.itemInventory[i].itemName, i);
        }
    }

    printf("\n\n");
}