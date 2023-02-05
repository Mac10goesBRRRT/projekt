#ifdef TEST

#include "unity.h"
#include "nav_helper.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_nav_helper(void)
{
    /* arrange */
    // Hier die Werte eingeben
    char* stringToCheckIsTrue = "#test";
    char* stringToCheckIsFalse = "test";

    /* act */
    // Die Funktion wird ausgeführt 
    bool valueIsTrue = startsWith(stringToCheckIsTrue,"#");
    bool valueIsFalse = startsWith(stringToCheckIsFalse, "#");

    //Output
    printf("%s startet mit '#' = %d\n",stringToCheckIsTrue, valueIsTrue);
    printf("%s startet mit '#' = %d",stringToCheckIsFalse, valueIsFalse);

    /* assert */
    // Vergleichen mit Inhalt
    TEST_ASSERT_TRUE(valueIsTrue);
    TEST_ASSERT_FALSE(valueIsFalse);
}

#endif // TEST