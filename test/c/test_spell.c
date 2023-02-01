#ifdef TEST
#include "unity.h"
#include "character.h"
#include "spell.h"

Player testPlayer;
Player testPlayer2;

void setUp(void)
{
    testPlayer.healthPoints = 0;
    testPlayer2.healthPoints = 15;
    testPlayer.strength = 0;
    testPlayer2.strength = 5;
    testPlayer.dexterity = 0;
    testPlayer2.dexterity = 5;
    testPlayer.intelligence = 0;
    testPlayer2.intelligence = 7;
    testPlayer.level = 0;
    testPlayer2.level = 5;
    testPlayer.exp = 50;
    testPlayer2.exp = 110;
    testPlayer.maxExp = 100;
    testPlayer2.maxExp = 100;
    testPlayer.attack = 5;
    testPlayer2.weaponClass = SWORD;
}

void tearDown(void)
{
}

void test_spellFireball(void)
{
    SpellEffect result = spellFireball(&testPlayer);
    TEST_ASSERT_EQUAL_INT(10,result.damage);
    result = spellFireball(&testPlayer2);
    TEST_ASSERT_EQUAL_INT(13,result.damage);
}

void test_spellHeal(void)
{

    int result = spellHeal(&testPlayer).healing;
    TEST_ASSERT_EQUAL_INT(10,result);
    result = spellHeal(&testPlayer2).healing;
    TEST_ASSERT_EQUAL_INT(12,result);
}

void test_spellLightning(void)
{
    int result = spellLightning(&testPlayer).damage;
    TEST_ASSERT_EQUAL_INT(10,result);
    result = spellLightning(&testPlayer2).damage;
    TEST_ASSERT_EQUAL_INT(13,result);
}

void test_spellRegeneration(void)
{
    int result = spellRegeneration(&testPlayer).healing;
    TEST_ASSERT_EQUAL_INT(5,result);
    result = spellRegeneration(&testPlayer2).healing;
    TEST_ASSERT_EQUAL_INT(6,result);
}
#endif // TEST