#ifdef TEST
#include "unity.h"
#include "character.h"
Player testPlayer;
Player testPlayer2;
Weapon testWeapon;

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

    testWeapon.attack = 5;
    testWeapon.durability = 100;
}

void tearDown(void)
{
}

void test_setPlayerHealthPoints(void)
{
    TEST_ASSERT_EQUAL_INT(0,testPlayer.healthPoints);
    setPlayerHealthPoints(&testPlayer,50);
    TEST_ASSERT_EQUAL_INT(50,testPlayer.healthPoints);
}

void test_getPlayerHealthPoints (void) {
    TEST_ASSERT_EQUAL_INT(15,getPlayerHealthPoints(&testPlayer2));
}

void test_setPlayerStrenght(void) {
    TEST_ASSERT_EQUAL_INT(0,testPlayer.strength);
    setPlayerStrength(&testPlayer,50);
    TEST_ASSERT_EQUAL_INT(50,testPlayer.strength);
}

void test_getPlayerStrength(void) {
    TEST_ASSERT_EQUAL_INT(5,getPlayerStrength(&testPlayer2));
}

void test_setPlayerDexterity(void) {
    TEST_ASSERT_EQUAL_INT(0,testPlayer.dexterity);
    setPlayerDexterity(&testPlayer,50);
    TEST_ASSERT_EQUAL_INT(50,testPlayer.dexterity);
}

void test_getPlayerDexterity(void) {
    TEST_ASSERT_EQUAL_INT(5,getPlayerDexterity(&testPlayer2));
}

void test_setPlayerIntelligence(void) {
    TEST_ASSERT_EQUAL_INT(0,testPlayer.intelligence);
    setPlayerIntelligence(&testPlayer,45);
    TEST_ASSERT_EQUAL_INT(45,testPlayer.intelligence);
}

void test_getPlayerIntelligence(void) {
    TEST_ASSERT_EQUAL_INT(7,getPlayerIntelligence(&testPlayer2));
}

void test_setPlayerLevel(void) {
    TEST_ASSERT_EQUAL_INT(0,testPlayer.level);
    setPlayerLevel(&testPlayer,1);
    TEST_ASSERT_EQUAL_INT(1,testPlayer.level);
}

void test_getPlayerLevel(void) {
    TEST_ASSERT_EQUAL_INT(5,getPlayerLevel(&testPlayer2));
}

void test_increaseStat(void) {
    increaseStat(&testPlayer2,STRENGTH,15);
    TEST_ASSERT_EQUAL_INT(20,testPlayer2.strength);
    increaseStat(&testPlayer2,INTELLIGENCE,15);
    TEST_ASSERT_EQUAL_INT(22,testPlayer2.intelligence);
    increaseStat(&testPlayer2,LEVEL,15);
    TEST_ASSERT_EQUAL_INT(20,testPlayer2.level);
}

void test_calculateStatIncrease(void) {
    TEST_ASSERT_EQUAL_INT(5,testPlayer2.level);
    TEST_ASSERT_EQUAL_INT(25,calculateStatIncrease(&testPlayer2,5));
}

void test_levelUp_enoughExp (void) {
    TEST_ASSERT_EQUAL_INT(5,testPlayer2.level);
    levelUp(&testPlayer2);
    TEST_ASSERT_EQUAL_INT(6,testPlayer2.level);
}

void test_levelUp_enoughExp_loseExp (void) {
    TEST_ASSERT_EQUAL_INT(110,testPlayer2.exp);
    TEST_ASSERT_EQUAL_INT(100,testPlayer2.maxExp);
    levelUp(&testPlayer2);
    TEST_ASSERT_EQUAL_INT(10,testPlayer2.exp);
}

void test_levelUp_notEnoughExp (void) {
    TEST_ASSERT_EQUAL_INT(0,testPlayer.level);
    levelUp(&testPlayer);
    TEST_ASSERT_EQUAL_INT(0,testPlayer.level);
}

void test_levelUp_notEnoughExp_loseExp (void) {
    TEST_ASSERT_EQUAL_INT(50,testPlayer.exp);
    TEST_ASSERT_EQUAL_INT(100,testPlayer.maxExp);
    levelUp(&testPlayer);
    TEST_ASSERT_EQUAL_INT(50,testPlayer.exp);
}

void test_calculateDamage_Sword (void) {
    setPlayerWeaponClass(&testPlayer2,SWORD);
    
    TEST_ASSERT_EQUAL_INT(25,calculateDamage(&testPlayer2,&testWeapon));
}

void test_calculateDamage_Bow (void) {
    setPlayerWeaponClass(&testPlayer2,BOW);

    TEST_ASSERT_EQUAL_INT(25,calculateDamage(&testPlayer2,&testWeapon));
}

void test_calculateDamage_Staff (void) {
    setPlayerWeaponClass(&testPlayer2,STAFF);

    TEST_ASSERT_EQUAL_INT(35,calculateDamage(&testPlayer2,&testWeapon));
}
#endif // TEST