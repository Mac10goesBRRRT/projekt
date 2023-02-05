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

void test_setFullName(void)
{
    // arrange
    char *fullNameWeapon = "switchblade v2", *result;

    // act
    Weapon test;
    setFullName(&test, fullNameWeapon);
    result = test.fullName;

    // output
    printf("setFullName | fullName set to: %s -> after set: %s", fullNameWeapon, result);

    // assert
    TEST_ASSERT_EQUAL(fullNameWeapon, result);
}

void test_getTypeID(void)
{
    // arrange
    int type = 1, result;
    Weapon test;
    test.typeID = type;

    /* act */
    // Die Funktion wird ausgeführt
    result = getTypeID(&test);

    // output
    printf("getTypeID | typeID should be: %d -> is: %d", type, result);

    // assert
    TEST_ASSERT_EQUAL(type, result);
}

void test_setTypeID(void)
{
    // arrange
    int type = 2, result;

    // act
    Weapon test;
    setTypeID(&test, type);
    result = test.typeID;

    // output
    printf("setTypeID | typeID set to: %d -> after set: %d", type, result);

    // assert
    TEST_ASSERT_EQUAL(type, result);
}

void test_getDamageModifier(void)
{
    // arrange
    int damageModifier = 2, result;
    Weapon test;
    test.damageModifier = damageModifier;

    /* act */
    // Die Funktion wird ausgeführt
    result = getDamageModifier(&test);

    // output
    printf("getDamageModifier | damageModifier should be: %d -> is: %d", damageModifier, result);

    // assert
    TEST_ASSERT_EQUAL(damageModifier, result);
}

void test_setDamageModifier(void)
{
    // arrange
    int damageModifier = 5, result;

    // act
    Weapon test;
    setDamageModifier(&test, damageModifier);
    result = test.damageModifier;

    // output
    printf("setDamageModifier | damageModifier set to: %d -> after set: %d", damageModifier, result);

    // assert
    TEST_ASSERT_EQUAL(damageModifier, result);
}

void test_getBaseDamage(void)
{
    // arrange
    int baseDamage = 10, result;
    Weapon test;
    test.baseDamage = baseDamage;

    /* act */
    // Die Funktion wird ausgeführt
    result = getBaseDamage(&test);

    // output
    printf("getBaseDamage | baseDamage should be: %d -> is: %d", baseDamage, result);

    // assert
    TEST_ASSERT_EQUAL(baseDamage, result);
}

void test_setBaseDamage(void)
{
    // arrange
    int baseDamage = 43, result;

    // act
    Weapon test;
    setBaseDamage(&test, baseDamage);
    result = test.baseDamage;

    // output
    printf("setBaseDamage | baseDamage set to: %d -> after set: %d", baseDamage, result);

    // assert
    TEST_ASSERT_EQUAL(baseDamage, result);
}

#endif // TEST
