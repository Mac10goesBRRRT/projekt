//bibs
#include <stdbool.h>

//headers
#include "nav_helper.h"

bool startsWith(const char *a, const char *b)
{
    if (strncmp(a, b, strlen(b)) == 0)
        return 1;
    return 0;
};