#ifdef TEST

#include "unity.h"
#include "player.h"
#include "items.h"
#include "nav_helper.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addItemToInventory(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    int shopItemIndex = 1;
    Player actualPlayer;
    Item *availableItems = getItems("./src/content/items.map");

    /* act */
    // Die Funktion wird ausgeführt
    actualPlayer = addItemToInventory(availableItems, shopItemIndex, actualPlayer);

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_EQUAL_INT(shopItemIndex, actualPlayer.itemInventory[0].id);
}

#endif // TEST
