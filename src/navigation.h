#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct room
{
    int id;
    char nameRoom[20];
    char msgRoom[150];
    int successor;
    int predecessor;
    char items[10];
    bool shopAvailable;
};

#endif // NAVIGATION_H
