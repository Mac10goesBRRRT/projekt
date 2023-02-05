#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "shop.h"

int openShop(Item *availableItems)
{
    int userInput;
    fflush(stdout);
    bool shopIsOpen = 1;
    while (shopIsOpen == 1)
    {
        printf("*** SHOP-Items *** \n\n");

        // printf("%-5s %-30s %5s\n", "Index", "Name", "Price");
        for (int i = 0; i < 6; i++)
        {
            printf("%-5d %-40s %5d$\n", availableItems[i].id, availableItems[i].itemName, availableItems[i].price);
        }

        printf("\n-> to buy items type '[index of item]' \n-> write '0' to quit the shop'\n\n");

        while (scanf("%d", &userInput) != 1)
        {
            printf("Invalid [index]. Please try again: ");
            fflush(stdout);
        }

        if (userInput > 0)
        {
            return userInput;
            // BUY ITEM added later -> addItemToInventory(userInput);
        }
        else if (userInput == 0)
        {
            shopIsOpen = 0;
            printf("Enjoy your items, have a great day!\n");
            return 0;
        }
        else
        {
            printf("Invalid [index]. Please try again: ");
        }
    }

    return 0;
}