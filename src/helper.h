#ifndef HELPER_H
#define HELPER_H

//BIBs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//defs
#define itemsMax 6
#define itemAttributesMax 2
#define maxItems 100
#define MAX_LINE_LENGTH 80 // for instructions
#define mapMax 4		   // for instructions
#define roomAttributesMax 7

bool startsWith(const char *a, const char *b)
{
    if (strncmp(a, b, strlen(b)) == 0)
        return 1;
    return 0;
};


#endif // HELPER_H