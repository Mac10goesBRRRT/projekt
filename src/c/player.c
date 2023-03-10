#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "player.h"

// PLAYER INVENTORY

// add and remove
Player addItemToInventory(Item *availableItems, int itemIndex, Player actualPlayer)
{
    int counter = actualPlayer.itemCounter;
    actualPlayer.itemInventory[counter] = availableItems[itemIndex - 1]; // -1 to get right index (items begin - 1,2,3,4...)
    actualPlayer.itemCounter += 1;

    return actualPlayer;
}

Player removeItemFromInventory(int itemIndex, Player actualPlayer)
{
    Item items[maxItems]; //    actualPlayer.itemInventory
    int i, index = -1;

    for (i = 0; i < maxItems; i++)
    {
        if (i == itemIndex)
        {
            // printf("%d - '%s'  has been removed from inventory.\n", actualPlayer.itemInventory[i].id, actualPlayer.itemInventory[i].itemName);
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        // shift all the element from index+1 by one position to the left
        for (i = index; i < maxItems - 1; i++)
            actualPlayer.itemInventory[i] = actualPlayer.itemInventory[i + 1];

        /*printf("New Array : ");
        for(i = 0; i < maxItems - 1; i++)
            printf("%d ",actualPlayer.itemInventory[i].id);*/
    }
    else
        printf("Element Not Found\n");

    actualPlayer.itemCounter = actualPlayer.itemCounter - 1;

    return actualPlayer;
}

// currency
Player setTotal(Player actualPlayer, int value)
{
    actualPlayer.wallet = value;
    return actualPlayer;
}

Player addMoneyToPlayer(Player actualPlayer, int money)
{
    int newTotal = money + actualPlayer.wallet;
    actualPlayer = setTotal(actualPlayer, newTotal);
    return actualPlayer;
}

Player removeMoneyFromPlayer(Player actualPlayer, int money)
{
    int newTotal = actualPlayer.wallet - money;
    actualPlayer = setTotal(actualPlayer, newTotal);
    return actualPlayer;
}

//add and remove items with currency
Player buyItem(Item *availableItems, int itemIndex, Player actualPlayer)
{
    int itemPrice = availableItems[itemIndex - 1].price;
    if (actualPlayer.wallet >= itemPrice)
    {
        actualPlayer = addItemToInventory(availableItems, itemIndex, actualPlayer);
        actualPlayer = removeMoneyFromPlayer(actualPlayer, itemPrice);
        printf("You bought item[%d] for %d$! \nYour balance is now: %d$\n", itemIndex, itemPrice, actualPlayer.wallet);
        return actualPlayer;
    }
    else
    {
        printf("You don't have enough money.\n\n");
        return actualPlayer;
    }
}

Player sellItem(int itemIndex, Player actualPlayer)
{
    int priceItemSell = actualPlayer.itemInventory[itemIndex].price;
    actualPlayer = addMoneyToPlayer(actualPlayer, actualPlayer.itemInventory[itemIndex].price / 2);
    printf("Item has been sold for 50%% of the purchase price (purchase price: %d$)! \nYour balance is now: %d$\n", priceItemSell, actualPlayer.wallet);

    actualPlayer = removeItemFromInventory(itemIndex, actualPlayer);
    return actualPlayer;
}

// show
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
