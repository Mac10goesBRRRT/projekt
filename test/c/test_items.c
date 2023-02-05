#ifdef TEST

#include "unity.h"
#include "nav_helper.h"
#include "items.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_items(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    Item* items;
    int expectedItemID = 1;
    int expectedSecondItemID = 2;

    /* act */
    // Die Funktion wird ausgeführt
    items = getItems("./src/content/items.map");

    /* make visible OUTPUT */
    for(int i=0; i<4;i++){
        printf("%s\n", items[i].itemName);
    }

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_EQUAL_INT(expectedItemID, items[0].id);
    TEST_ASSERT_EQUAL_INT(expectedSecondItemID, items[1].id);
}

#endif // TEST
