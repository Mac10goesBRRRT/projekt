#ifdef TEST

#include "unity.h"
#include "player.h"
#include "items.h"
#include "nav_helper.h"

Item *availableItems;
Player actualPlayer;
void setUp(void)
{
    availableItems = getItems("./src/content/items.map");
}

void tearDown(void)
{
}

void test_addItemToInventory(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    int shopItemIndex = 1;

    /* act */
    // Die Funktion wird ausgeführt
    actualPlayer = addItemToInventory(availableItems, shopItemIndex, actualPlayer);

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_EQUAL_INT(shopItemIndex, actualPlayer.itemInventory[0].id);
}

void test_removeItemFromInventory(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    int itemToRemove = 0; // index to remove (we already bought it in function above)

    /* act */
    // Die Funktion wird ausgeführt
    Item itemBeforeRemove = actualPlayer.itemInventory[0];
    actualPlayer = removeItemFromInventory(itemToRemove, actualPlayer); // then remove
    Item itemAfterRemove = actualPlayer.itemInventory[0];

    // OUTPUT

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_NOT_EQUAL_UINT8(itemBeforeRemove.id, itemAfterRemove.id);
}

#endif // TEST
