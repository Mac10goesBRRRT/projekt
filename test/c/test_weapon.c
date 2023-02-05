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

void test_setName(void)
{
    // arrange
    char *nameWeapon = "switchblade", *result;

    // act
    Weapon test;
    setName(&test, nameWeapon);
    result = test.name;

    // output
    printf("setName | name set to: %s -> after set: %s", nameWeapon, result);

    // assert
    TEST_ASSERT_EQUAL(nameWeapon, result);
}

void test_getFullName(void)
{
    // arrange
    char *nameOfWeapon = "Kukri v2", *result;
    Weapon test;
    test.fullName = nameOfWeapon;

    /* act */
    // Die Funktion wird ausgeführt
    result = getFullName(&test);

    // output
    printf("getFullName | fullName should be: %s -> is: %s", nameOfWeapon, result);

    // assert
    TEST_ASSERT_EQUAL(nameOfWeapon, result);
}

#endif // TEST
