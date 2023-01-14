#ifndef NAVIGATION_H
#define NAVIGATION_H

struct room
{
    int id;
    char nameRoom[20];
    char msgRoom[150];
    int successor;
    int predecessor;
    char items[10];
};

#endif // NAVIGATION_H
