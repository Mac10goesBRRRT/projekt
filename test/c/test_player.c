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
    printf("removeItem | ID_before: %d -> ID_after: %d", itemBeforeRemove.id, itemAfterRemove.id);

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_NOT_EQUAL_UINT8(itemBeforeRemove.id, itemAfterRemove.id);
}

void test_setTotal(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    int setMoney = 100;

    /* act */
    // Die Funktion wird ausgeführt
    int valueBefore = actualPlayer.wallet;
    actualPlayer = setTotal(actualPlayer, setMoney);
    int valueAfter = actualPlayer.wallet;

    // OUTPUT
    printf("setTotal | before: %d -> after: %d", valueBefore, valueAfter);

    /* assert */
    // Vergleichen mit Inhalt
    TEST_ASSERT_EQUAL_INT(setMoney, actualPlayer.wallet);
    TEST_ASSERT_NOT_EQUAL_UINT8(valueBefore, valueAfter);
}

void test_addMoneyToPlayer(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    // balance = 70
    int valueToAdd = 20;
    int checkSum = actualPlayer.wallet + valueToAdd;

    /* act */
    // Die Funktion wird ausgeführt
    actualPlayer = addMoneyToPlayer(actualPlayer, valueToAdd);

    // OUTPUT
    printf("%d$ has been added to your balance. TOTAL: %d$", valueToAdd, actualPlayer.wallet);

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_EQUAL_INT(checkSum, actualPlayer.wallet);
}

void test_removeMoneyFromPlayer(void)
{
    /* arrange */
    // Hier die Werte eingeben/deklarieren
    int valueToRemove = 20;
    int checkSum = actualPlayer.wallet - valueToRemove;
    
    /* act */
    // Die Funktion wird ausgeführt
    actualPlayer = removeMoneyFromPlayer(actualPlayer, valueToRemove);

    // OUTPUT
    printf("%d$ has been removed from your balance. TOTAL: %d$", valueToRemove, actualPlayer.wallet);

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_EQUAL_INT(checkSum, actualPlayer.wallet);
}




#endif // TEST
