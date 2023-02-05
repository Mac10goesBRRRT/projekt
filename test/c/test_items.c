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
    Item *items;
    int expectedItemID = 1;
    int expectedSecondItemID = 2;

    /* act */
    // Die Funktion wird ausgeführt
    items = getItems("./src/content/items.map");

    /* make visible OUTPUT */
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", items[i].itemName);
    }

    /* assert */
    // Vergleichen mit Inhalt von game.Map File
    TEST_ASSERT_EQUAL_INT(expectedItemID, items[0].id);
    TEST_ASSERT_EQUAL_INT(expectedSecondItemID, items[1].id);
}

void test_setItemPrice(void)
{
    // arrange
    int price = 50, result;

    // act
    Item test;
    setItemPrice(&test, price);
    result = test.price;

    //output
    printf("---------------------------------------------------\n");
    printf("setItemPrice | price to set: %d -> item.price: %d", price, result);

    // assert
    TEST_ASSERT_EQUAL(price, result);
}


void test_getItemPrice(void)
{
    // arrange
    int price = 50, result;

    // act
    Item test;
    test.price = price;
    result = getItemPrice(&test);

    //output
    printf("getItemPrice | price should be: %d -> price is: %d", price, result);

    // assert
    TEST_ASSERT_EQUAL(price, result);
}

#endif // TEST
