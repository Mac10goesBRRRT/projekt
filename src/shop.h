#ifndef SHOP_H
#define SHOP_H

#include "helper.h"

int openShop(struct item itemList[itemsMax])
{
    printf("*** SHOP-Items *** \n\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%d - %s\n", itemList[i].id, itemList[i].itemName);
    }

    printf("\n-> to buy items type '[index of item]' \n-> write '0' to quit the shop'\n\n");

    char userInput[1];
    bool accept = 0;
    while (accept == 0)
    {
        scanf(" %c", userInput);
        if (atoi(userInput) == 0)
        {
            accept = 1;
            printf("Enjoy your items, have a great day!");
            return 0;
        }
        else if (atoi(userInput) != 0)
        {
            accept = 1;
            printf("You bought ITEM: %d \n", atoi(userInput));
            return atoi(userInput);
        }
        else
        {
            printf("Invalid Input!\n");
        }
    }

}

#endif // SHOP_H