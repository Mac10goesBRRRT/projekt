#ifdef TEST
#include "unity.h"
#include "character.h"
#include "spell.h"

Character testCharacter;
Character testCharacter2;

void setUp(void)
{
    testCharacter.healthPoints = 0;
    testCharacter2.healthPoints = 15;
    testCharacter.strength = 0;
    testCharacter2.strength = 5;
    testCharacter.dexterity = 0;
    testCharacter2.dexterity = 5;
    testCharacter.intelligence = 0;
    testCharacter2.intelligence = 7;
    testCharacter.level = 0;
    testCharacter2.level = 5;
    testCharacter.exp = 50;
    testCharacter2.exp = 110;
    testCharacter.maxExp = 100;
    testCharacter2.maxExp = 100;
    testCharacter.attack = 5;
    testCharacter2.weaponClass = SWORD;
}

void tearDown(void)
{
}

void test_spellFireball(void)
{
    int result = spellFireball(&testCharacter).damage;
    TEST_ASSERT_EQUAL_INT(10,result);
    result = spellFireball(&testCharacter2).damage;
    TEST_ASSERT_EQUAL_INT(13,result);
}

void test_spellHeal(void)
{

    int result = spellHeal(&testCharacter).healing;
    TEST_ASSERT_EQUAL_INT(10,result);
    result = spellHeal(&testCharacter2).healing;
    TEST_ASSERT_EQUAL_INT(12,result);
}

void test_spellLightning(void)
{
    int result = spellLightning(&testCharacter).damage;
    TEST_ASSERT_EQUAL_INT(10,result);
    result = spellLightning(&testCharacter2).damage;
    TEST_ASSERT_EQUAL_INT(13,result);
}

void test_spellRegeneration(void)
{
    int result = spellRegeneration(&testCharacter).healing;
    TEST_ASSERT_EQUAL_INT(5,result);
    result = spellRegeneration(&testCharacter2).healing;
    TEST_ASSERT_EQUAL_INT(6,result);
}
#endif // TEST