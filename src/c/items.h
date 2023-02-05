#ifndef ITEMS_H
#define ITEMS_H

#define itemAttributesMax 4 // for items
#define maxItems 100        // for inventory/item list

#include <stdbool.h>

typedef struct
{
	int id;
	char itemName[50];
	bool inShopAvailable;
	int price;
} Item;

Item *getItems(char *itemsMapFile);


void setItemPrice(Item* item, int price);

#endif