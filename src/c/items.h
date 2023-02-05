#ifndef ITEMS_H
#define ITEMS_H

#define itemAttributesMax 4 // for items
#define maxItems 100		// for inventory/item list

#include <stdbool.h>

typedef struct
{
	int id;
	char itemName[50];
	bool inShopAvailable;
	int price;
} Item;

Item *getItems(char *itemsMapFile);

int getItemPrice(Item *item);
void setItemPrice(Item *item, int price);

int getItemShopAvailable(Item *item);
void setItemShopAvailable(Item *item, bool value);

#endif