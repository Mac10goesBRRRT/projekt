#ifdef TEST

#include "unity.h"
#include "map.h"
#include "nav_helper.h"

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
    Room* map;

    /* act */
    // Die Funktion wird ausgeführt
    map = getMap("./src/content/game.map");

    for(int i=0; i<4;i++){
        printf("%s\n", map[i].nameRoom);
    }

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    int officeExpectedSuccessor = 1;
    int officeExpectedID = 0;

    int fdExpectedSuccessor = 3;
    int fdExpectedID = 2;

    TEST_ASSERT_EQUAL_INT(officeExpectedSuccessor, map[0].successor);
    TEST_ASSERT_EQUAL_INT(officeExpectedID, map[0].id);

    TEST_ASSERT_EQUAL_INT(fdExpectedSuccessor, map[2].successor);
    TEST_ASSERT_EQUAL_INT(fdExpectedID, map[2].id);
}

#endif // TEST
