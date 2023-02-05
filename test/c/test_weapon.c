#ifdef TEST

#include "unity.h"
#include "weapon.h"

void setUp(void)
{

}

void tearDown(void)
{
}


void test_getName(void)
{
    // arrange
    char *nameOfWeapon = "Kukri", *result;
    Weapon test;
    test.name = nameOfWeapon;

    /* act */
    // Die Funktion wird ausgeführt
    result = getName(&test);

    // output
    printf("getName | name should be: %s -> is: %s", nameOfWeapon, result);

    // assert
    TEST_ASSERT_EQUAL(nameOfWeapon, result);
}

#endif // TEST
