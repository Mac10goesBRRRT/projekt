#ifdef TEST

#include "unity.h"

#include "map.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_map(void)
{
    /* arrange */
    // Hier die Werte eingeben
    struct room* map;

    /* act */
    // Die Funktion wird ausgeführt
    map = getMap();

    for(int i=0; i<4;i++){
        printf("%s\n", map[i].nameRoom);
    }

    /* assert */
    // Vergleichen
    int expectedSuccessor = 1;
    TEST_ASSERT_EQUAL_INT(expectedSuccessor, map[0].successor);
}

#endif // TEST
