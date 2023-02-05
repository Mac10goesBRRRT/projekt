#ifdef TEST

#include "unity.h"
#include "commands.h"
#include "map.h"
#include "nav_helper.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_commands(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    Room* mapData;
    mapData = getMap("./src/content/game.map");
    int playerPosition = 3; //last player position in north - so you can only move to south
    char* expectedString = "You can move south from here\n";

    /* act */
    // Die Funktion wird ausgeführt
    char* msg = getPossibleCommands(mapData[playerPosition], playerPosition);

    /* TEST AUSGABE zur Kontrolle */
    printf("%s", msg);

    /* assert */
    // Vergleichen mit Inhalt
    TEST_ASSERT_EQUAL_STRING(expectedString, msg);
}

#endif // TEST