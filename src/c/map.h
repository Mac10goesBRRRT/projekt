#ifndef MAP_H
#define MAP_H

//bibs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "nav_helper.h"

//defs
#define mapMax 4		    // for map (adjust to txt count of rooms -> game.map)
#define roomAttributesMax 7 // for room struct (adjust to txt count of room-attributes -> game.map)

typedef struct Room
{
	int id;
	char nameRoom[20];
	char msgRoom[150];
	int successor;
	int predecessor;
	char items[10];
	bool shopAvailable;
} Room;

Room *getMap(char *gameMapFile);


int getRoomSuccessor(Room *room);
void setRoomSuccessor(Room *room, int successorSet);

int getRoomPredecessor(Room *room);
void setRoomPredecessor(Room *room, int predecessorSet);

bool getRoomShopAvailable(Room *room);
void setRoomShopAvailable(Room *room, bool shopAvailableSet);

#endif // MAP_H