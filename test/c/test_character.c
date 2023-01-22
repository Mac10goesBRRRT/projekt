#ifdef TEST
#include "unity.h"
#include "character.h"
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
    testCharacter.statPoints = 0;
    testCharacter2.statPoints = 25;
}

void tearDown(void)
{
}

void test_setCharacterHealthPoints(void)
{
    TEST_ASSERT_EQUAL_INT(0,testCharacter.healthPoints);
    setCharacterHealthPoints(&testCharacter,50);
    TEST_ASSERT_EQUAL_INT(50,testCharacter.healthPoints);
}

void test_getCharacterHealthPoints (void) {
    TEST_ASSERT_EQUAL_INT(15,getCharacterHealthPoints(&testCharacter2));
}

void test_setCharacterStrenght(void) {
    TEST_ASSERT_EQUAL_INT(0,testCharacter.strength);
    setCharacterStrength(&testCharacter,50);
    TEST_ASSERT_EQUAL_INT(50,testCharacter.strength);
}

void test_getCharacterStrength(void) {
    TEST_ASSERT_EQUAL_INT(5,getCharacterStrength(&testCharacter2));
}

void test_setCharacterDexterity(void) {
    TEST_ASSERT_EQUAL_INT(0,testCharacter.dexterity);
    setCharacterDexterity(&testCharacter,50);
    TEST_ASSERT_EQUAL_INT(50,testCharacter.dexterity);
}

void test_getCharacterDexterity(void) {
    TEST_ASSERT_EQUAL_INT(5,getCharacterDexterity(&testCharacter2));
}

void test_setCharacterIntelligence(void) {
    TEST_ASSERT_EQUAL_INT(0,testCharacter.intelligence);
    setCharacterIntelligence(&testCharacter,45);
    TEST_ASSERT_EQUAL_INT(45,testCharacter.intelligence);
}

void test_getCharacterIntelligence(void) {
    TEST_ASSERT_EQUAL_INT(7,getCharacterIntelligence(&testCharacter2));
}

void test_setCharacterLevel(void) {
    TEST_ASSERT_EQUAL_INT(0,testCharacter.level);
    setCharacterLevel(&testCharacter,1);
    TEST_ASSERT_EQUAL_INT(1,testCharacter.level);
}

void test_getCharacterLevel(void) {
    TEST_ASSERT_EQUAL_INT(5,getCharacterLevel(&testCharacter2));
}

void test_increaseStat(void) {
    increaseStat(&testCharacter2,STRENGTH,15);
    TEST_ASSERT_EQUAL_INT(20,testCharacter2.strength);
    increaseStat(&testCharacter2,INTELLIGENCE,15);
    TEST_ASSERT_EQUAL_INT(22,testCharacter2.intelligence);
    increaseStat(&testCharacter2,LEVEL,15);
    TEST_ASSERT_EQUAL_INT(20,testCharacter2.level);
}

void test_calculateStatIncrease_enoughStatPoints (void) {
    TEST_ASSERT_EQUAL_INT(25,testCharacter2.statPoints);
    TEST_ASSERT_EQUAL_INT(5,calculateStatIncrease(&testCharacter2));
    TEST_ASSERT_EQUAL_INT(24,testCharacter2.statPoints);
}

void test_levelUp_enoughExp (void) {
    TEST_ASSERT_EQUAL_INT(5,testCharacter2.level);
    levelUp(&testCharacter2);
    TEST_ASSERT_EQUAL_INT(6,testCharacter2.level);
}

void test_levelUp_enoughExp_loseExp (void) {
    TEST_ASSERT_EQUAL_INT(110,testCharacter2.exp);
    TEST_ASSERT_EQUAL_INT(100,testCharacter2.maxExp);
    levelUp(&testCharacter2);
    TEST_ASSERT_EQUAL_INT(10,testCharacter2.exp);
}

void test_levelUp_notEnoughExp (void) {
    TEST_ASSERT_EQUAL_INT(0,testCharacter.level);
    levelUp(&testCharacter);
    TEST_ASSERT_EQUAL_INT(0,testCharacter.level);
}

void test_levelUp_notEnoughExp_loseExp (void) {
    TEST_ASSERT_EQUAL_INT(50,testCharacter.exp);
    TEST_ASSERT_EQUAL_INT(100,testCharacter.maxExp);
    levelUp(&testCharacter);
    TEST_ASSERT_EQUAL_INT(50,testCharacter.exp);
}

#endif // TEST