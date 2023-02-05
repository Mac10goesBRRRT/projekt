#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "shop.h"
#include "player.h"

int *openShop(Item *availableItems, Player actualPlayer)
{
    int mode = 0;
    int *x = malloc(sizeof(int) * 2);

    int userModeInput;
    fflush(stdout);
    bool selectMode = 1;
    while (selectMode == 1)
    {
        printf("Please type '0' for buy or '1' to sell items!\n");
        while (scanf(" %d", &userModeInput) != 1)
        {
            printf("Invalid [index]. Please try again: ");
            fflush(stdout);
        }

        if (userModeInput > 1 || userModeInput < 0)
        {
            printf("Invalid [index]. Please try again: ");
        }
        else if (userModeInput == 0)
        {
            mode = 0;
            selectMode = 0;
        }
        else if (userModeInput == 1)
        {
            mode = 1;
            selectMode = 0;
        }
    }

    int userInput;
    fflush(stdout);
    bool shopIsOpen = 1;

    if (mode == 0)
    {

        while (shopIsOpen == 1)
        {
            printf("*** SHOP-Items *** \n\n");

            // printf("%-5s %-30s %5s\n", "Index", "Name", "Price");
            for (int i = 0; i < 6; i++)
            {
                printf("%-5d %-40s %5d$\n", availableItems[i].id, availableItems[i].itemName, availableItems[i].price);
            }

            printf("\n-> to buy items type '[index of item]' \n-> write '0' to quit the shop'\n\n");

            while (scanf(" %d", &userInput) != 1)
            {
                printf("Invalid [index]. Please try again: ");
                fflush(stdout);
            }

            if (userInput > 0)
            {
                x[0] = mode;
                x[1] = userInput;
                return x;
                // BUY ITEM added later -> addItemToInventory(userInput);
            }
            else if (userInput == 0)
            {
                shopIsOpen = 0;
                printf("Enjoy your items, have a great day!\n");
                x[0] = -1;
                x[1] = -1;
                return x;
            }
            else
            {
                printf("Invalid [index]. Please try again: ");
            }
        }
    }
    else if (mode == 1)
    {
        while (shopIsOpen == 1)
        {
            if (actualPlayer.itemCounter > 0)
            {
                printf("*** Your inventory *** \n\n");

                // printf("%-5s %-30s %5s\n", "Index", "Name", "Price");
                for (int i = 0; i < actualPlayer.itemCounter; i++)
                {
                    printf("%-5d %-40s %5d$\n", i+1, actualPlayer.itemInventory[i].itemName, actualPlayer.itemInventory[i].price);
                }

                printf("\n-> to sell items type '[index of item]' \n-> write '0' to quit the shop'\n\n");

                while (scanf(" %d", &userInput) != 1)
                {
                    printf("Invalid [index]. Please try again: ");
                    fflush(stdout);
                }

                if (userInput > 0)
                {
                    x[0] = mode;
                    x[1] = userInput-1; //index begin on 1 because we will cancel with 0
                    return x;
                    //  BUY ITEM added later -> addItemToInventory(userInput);
                }
                else if (userInput == 0)
                {
                    shopIsOpen = 0;
                    printf("Enjoy your money, have a great day!\n");
                    x[0] = -1;
                    x[1] = -1;
                    return x;
                }
                else
                {
                    printf("Invalid [index]. Please try again: ");
                }
            }
            else
            {
                shopIsOpen = 0;
                printf("*** Your inventory is empty *** \n\n");
                x[0] = -1;
                x[1] = -1;
                return x;
            }
        }
    }

    x[0] = -1;
    return x;
}